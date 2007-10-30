/*---------------------------------------------------------------------\
|                                                                      |
|                      __   __    ____ _____ ____                      |
|                      \ \ / /_ _/ ___|_   _|___ \                     |
|                       \ V / _` \___ \ | |   __) |                    |
|                        | | (_| |___) || |  / __/                     |
|                        |_|\__,_|____/ |_| |_____|                    |
|                                                                      |
|                               core system                            |
|                                                        (C) SuSE GmbH |
\----------------------------------------------------------------------/

   File:       NCSelectionBox.h

   Author:     Michael Andres <ma@suse.de>
   Maintainer: Michael Andres <ma@suse.de>

/-*/
#ifndef NCSelectionBox_h
#define NCSelectionBox_h

#include <iosfwd>

#include "YSelectionBox.h"
#include "NCPadWidget.h"
#include "NCTablePad.h"

class NCSelectionBox;

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : NCSelectionBox
//
//	DESCRIPTION :
//
class NCSelectionBox : public YSelectionBox, public NCPadWidget {

  friend std::ostream & operator<<( std::ostream & STREAM, const NCSelectionBox & OBJ );

  NCSelectionBox & operator=( const NCSelectionBox & );
  NCSelectionBox            ( const NCSelectionBox & );

  protected:

    /**
     * Overload myPad to narrow the type
     */
    virtual NCTablePad * myPad () const 
	{ return dynamic_cast<NCTablePad*> ( NCPadWidget::myPad () ); }

    bool          biglist;
    bool          immediate;
    
  protected:

    virtual const char * location() const { return "NCSelectionBox"; }

    virtual NCPad * CreatePad();
    virtual void    wRecoded();

  public:

    NCSelectionBox( NCWidget * parent, const YWidgetOpt & opt,
		    const YCPString & label );
    virtual ~NCSelectionBox();

    bool bigList() const { return biglist; }
    void setBigList( const bool big ) { biglist = big; }

    virtual void itemAdded( const YCPString& string, int index, bool selected );
    virtual long nicesize( YUIDimension dim );
    virtual void setSize( long newwidth, long newheight );

    virtual void setLabel( const YCPString & nlabel );

    virtual int getCurrentItem();
    virtual void setCurrentItem( int index );

    virtual NCursesEvent wHandleInput( wint_t key );

    virtual void setEnabling( bool do_bv ) { NCWidget::setEnabling( enabled=do_bv ); }

    virtual bool setKeyboardFocus() {
      if ( !grabFocus() )
        return YWidget::setKeyboardFocus();
      return true;
    }

    string getLine(const int & index );
    void clearTable( ) { myPad ()->ClearTable(); };

    void deleteAllItems();
};

///////////////////////////////////////////////////////////////////

#endif // NCSelectionBox_h