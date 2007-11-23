/*---------------------------------------------------------------------\
|								       |
|		       __   __	  ____ _____ ____		       |
|		       \ \ / /_ _/ ___|_   _|___ \		       |
|			\ V / _` \___ \ | |   __) |		       |
|			 | | (_| |___) || |  / __/		       |
|			 |_|\__,_|____/ |_| |_____|		       |
|								       |
|				core system			       |
|							 (C) SuSE GmbH |
\----------------------------------------------------------------------/

  File:	      YQMultiSelectionBox.cc

  Author:     Stefan Hundhammer <sh@suse.de>

/-*/


#include <limits.h>
#include <qstring.h>
#include <qlabel.h>
#include <qheader.h>
#define y2log_component "qt-ui"
#include <ycp/y2log.h>

using std::max;

#include "utf8.h"
#include "YQUI.h"
#include "YEvent.h"
#include "YQMultiSelectionBox.h"
#include "YQSignalBlocker.h"
#include "YQWidgetCaption.h"

#define DEFAULT_VISIBLE_LINES		5
#define SHRINKABLE_VISIBLE_LINES	2


YQMultiSelectionBox::YQMultiSelectionBox( YWidget *		parent,
					  const string &	label )
    : QVBox( (QWidget *) parent->widgetRep() )
    , YMultiSelectionBox( parent, label )
{
    setWidgetRep( this );

    setSpacing( YQWidgetSpacing );
    setMargin( YQWidgetMargin );

    _caption = new YQWidgetCaption( this, label );
    YUI_CHECK_NEW( _caption );
    
    _qt_listView = new QListView( this );
    YUI_CHECK_NEW( _qt_listView );
    
    _qt_listView->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding ) );
    _qt_listView->addColumn( "" );	// QListView doesn't have one single column by default!
    _qt_listView->setSorting( 0, false );
    _qt_listView->header()->setStretchEnabled( true );
    _qt_listView->header()->hide();
    _caption->setBuddy( _qt_listView );

    // Very small default size if specified

    connect( _qt_listView,	SIGNAL( selectionChanged() 	),
	     this, 	  	SLOT  ( slotSelected() 		) );

    connect( this,		SIGNAL( valueChanged()		),
	     this,		SLOT  ( slotValueChanged()	) );
}


YQMultiSelectionBox::~YQMultiSelectionBox()
{
    // NOP
}


void
YQMultiSelectionBox::setLabel( const string & label )
{
    _caption->setText( label );
    YMultiSelectionBox::setLabel( label );
}


void
YQMultiSelectionBox::addItem( YItem * yItem )
{
    YQSignalBlocker sigBlocker( _qt_listView );
    YMultiSelectionBox::addItem( yItem ); // will also check for NULL

    YQMultiSelectionBoxItem * msbItem =
	new YQMultiSelectionBoxItem( this, _qt_listView, yItem );

    YUI_CHECK_NEW( msbItem );

    // Take care of the item's check box
    
    if ( yItem->selected() )
	 msbItem->setOn( true );

    
    // Take care of the QListView's keyboard focus
    
    if ( ! _qt_listView->selectedItem() )
	_qt_listView->setSelected( msbItem, true );
}


void YQMultiSelectionBox::selectItem( YItem * yItem, bool selected )
{
    YMultiSelectionBox::selectItem( yItem, selected );
    YQMultiSelectionBoxItem * msbItem = findItem( yItem );

    if ( msbItem )
	msbItem->setOn( selected );
}


void
YQMultiSelectionBox::deselectAllItems()
{
    YQSignalBlocker sigBlocker( _qt_listView );
    YMultiSelectionBox::deselectAllItems();
    
    QListViewItemIterator it( _qt_listView );

    while ( *it )
    {
	YQMultiSelectionBoxItem * item = dynamic_cast<YQMultiSelectionBoxItem *> (*it);

	if ( item )
	    item->setOn( false );

	++it;
    }
}


void
YQMultiSelectionBox::deleteAllItems()
{
    YQSignalBlocker sigBlocker( _qt_listView );

    YMultiSelectionBox::deleteAllItems();
    _qt_listView->clear();
}


YItem *
YQMultiSelectionBox::currentItem()
{
    // QListView::currentItem() is very similar, but not exactly the same as
    // QListView::selectedItem(), and it is NOT to be confused with an item's
    // "selected" state in a YQMultiSelectionBox (the item's check box):
    //
    // QListView::currentItem() is the item that currently has the keyboard
    // focus. By default, it is displayed with a faint dotted outline.
    //
    // QListView::selectedItem() is the item that is selected in the QListView
    // widget. It is displayed a very visible with inverted colors (typically
    // blue backround). If there is a selected item, it is also the current
    // item. if there is no selected item, there might still be a current item,
    // though.
    //
    // The Y(Q)MultiSelectionBox item's "selected" state is completely
    // independent of all this: It only depends on the item's check
    // box. QListView::selectedItem() and QListView::currentItem() are just
    // mechanisms for keyboard navigation to show the user which item's check
    // box will be toggled when he hits the space bar.
    //
    // For the purpose of this function, QListView::currentItem() is the
    // minimum requirement.
    
    QListViewItem * currentQItem = _qt_listView->currentItem();

    if ( currentQItem )
    {
	YQMultiSelectionBoxItem * item = dynamic_cast<YQMultiSelectionBoxItem *> (currentQItem);

	if ( item )
	    return item->yItem();
    }

    return 0;
}


void
YQMultiSelectionBox::setCurrentItem( YItem * yItem )
{
    // See also explanations about QListView::currentItem() vs.
    // QListView::selectedItem() above
    //
    // This function uses QListView::selectedItem() for better visibility.
    // This implicitly also changes QListView::currentItem().
    
    YQSignalBlocker sigBlocker( _qt_listView );

    if ( ! yItem )
    {
	_qt_listView->clearSelection();
    }
    else
    {
	YQMultiSelectionBoxItem * msbItem = findItem( yItem );

	if ( msbItem )
	    _qt_listView->setSelected( msbItem, true );

	// This does NOT change the item's check box!
	// (see explanations in YQMultiSelectionBox::currentItem() avove)
    }
}


void
YQMultiSelectionBox::setEnabled( bool enabled )
{
    _caption->setEnabled( enabled );
    _qt_listView->setEnabled( enabled );
    _qt_listView->triggerUpdate();
    YWidget::setEnabled( enabled );
}


int YQMultiSelectionBox::preferredWidth()
{
    int hintWidth = _caption->isShown() ?
	_caption->sizeHint().width() + frameWidth() : 0;

    return max( 80, hintWidth );
}


int YQMultiSelectionBox::preferredHeight()
{
    int hintHeight	 = _caption->isShown() ? _caption->sizeHint().height() : 0;
    int visibleLines	 = shrinkable() ? SHRINKABLE_VISIBLE_LINES : DEFAULT_VISIBLE_LINES;
    hintHeight 		+= visibleLines * _qt_listView->fontMetrics().lineSpacing();
    hintHeight		+= _qt_listView->frameWidth() * 2;

    return max( 80, hintHeight );
}


void
YQMultiSelectionBox::setSize( int newWidth, int newHeight )
{
    resize( newWidth, newHeight );
}


bool
YQMultiSelectionBox::setKeyboardFocus()
{
    _qt_listView->setFocus();

    return true;
}


void
YQMultiSelectionBox::slotSelected()
{
    if ( notify() )
    {
	if ( ! YQUI::ui()->eventPendingFor( this ) )
	{
	    // Avoid overwriting a (more important) ValueChanged event with a SelectionChanged event

	    YQUI::ui()->sendEvent( new YWidgetEvent( this, YEvent::SelectionChanged ) );
	}
    }
}


void
YQMultiSelectionBox::slotValueChanged()
{
    if ( notify() )
	YQUI::ui()->sendEvent( new YWidgetEvent( this, YEvent::ValueChanged ) );
}


void
YQMultiSelectionBox::sendValueChanged()
{
    emit valueChanged();
}


YQMultiSelectionBoxItem *
YQMultiSelectionBox::findItem( YItem * wantedItem )
{
    // FIXME: Don't search through all items, use the YItem::data() pointer instead
    
    QListViewItemIterator it( _qt_listView );

    while ( *it )
    {
	YQMultiSelectionBoxItem * item = dynamic_cast<YQMultiSelectionBoxItem *> (*it);

	if ( item && item->yItem() == wantedItem )
	    return item;

	++it;
    }

    return 0;
}





int YQMultiSelectionBoxItem::_item_count = 0;



YQMultiSelectionBoxItem::YQMultiSelectionBoxItem( YQMultiSelectionBox *	parent,
						  QListView * 		listView,
						  YItem *		yItem )
    : QCheckListItem( listView, fromUTF8( yItem->label() ), QCheckListItem::CheckBox )
    , _yItem( yItem )
    , _multiSelectionBox( parent )
{
    YUI_CHECK_PTR( yItem );

    _serial = _item_count++;
}


void
YQMultiSelectionBoxItem::stateChange( bool newState )
{
    _yItem->setSelected( newState );
    _multiSelectionBox->sendValueChanged();
    QCheckListItem::stateChange( newState );
}


QString
YQMultiSelectionBoxItem::key( int, bool ) const
{
    /*
     * Return a sort key that depends on creation (i.e. insertion) order.
     */

    static QString sortKey;
    sortKey.sprintf( "%010d", INT_MAX - _serial );

    return sortKey;
}


#include "YQMultiSelectionBox.moc"
