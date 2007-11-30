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

  File:	      YQWidgetCaption.cc

  Author:     Stefan Hundhammer <sh@suse.de>

/-*/


#define y2log_component "qt-ui"
#include <ycp/y2log.h>

#include "YQWidgetCaption.h"
#include "utf8.h"


YQWidgetCaption::YQWidgetCaption( QWidget * parent, 
				  const string &  text )
    : QLabel( fromUTF8( text ), parent )
{
    setTextFormat( QLabel::PlainText );
    handleVisibility( text );
}


YQWidgetCaption::YQWidgetCaption( QWidget * parent, const QString & text )
    : QLabel( text, parent )
{
    setTextFormat( QLabel::PlainText );
    handleVisibility( text );
}


YQWidgetCaption::~YQWidgetCaption()
{
    // NOP
}


void YQWidgetCaption::setText ( const string  & newText )
{
    setText( fromUTF8( newText ) );
}


void YQWidgetCaption::setText ( const QString & newText )
{
    QLabel::setText( newText );
    handleVisibility( newText.isEmpty() );
}


void YQWidgetCaption::handleVisibility( const string  & text )
{
    handleVisibility( text.empty() );
}


void YQWidgetCaption::handleVisibility( const QString & text )
{
    handleVisibility( text.isEmpty() );
}


void YQWidgetCaption::handleVisibility( bool textIsEmpty )
{
    if ( textIsEmpty )
    {
	if ( isShown() )
	    hide();
    }
    else
    {
	if ( ! isShown() )
	    show();
    }
}


#include "YQWidgetCaption.moc"