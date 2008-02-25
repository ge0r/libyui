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

   File:       NCtext.h

   Author:     Michael Andres <ma@suse.de>
   Maintainer: Michael Andres <ma@suse.de>

/-*/
#ifndef NCtext_h
#define NCtext_h

#include <iosfwd>

#include <list>
using namespace std;

#include "NCstring.h"
#include "NCWidget.h"
class NCursesWindow;

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : NCtext
//
//	DESCRIPTION :
//
class NCtext {

  friend std::ostream & operator<<( std::ostream & STREAM, const NCtext & OBJ );

  public:

    typedef list<NCstring>::iterator       iterator;
    typedef list<NCstring>::const_iterator const_iterator;

  private:

    static const NCstring emptyStr;

  protected:

    list<NCstring> mtext;

    virtual void lset( const NCstring & ntext );
    void lbrset( const NCstring & ntext, size_t columns ); 

  public:

    NCtext( const NCstring & nstr = "" );
    NCtext( const NCstring & nstr, size_t columns );

    virtual ~NCtext();

    unsigned Lines()   const;
    size_t Columns() const;

    void append( const NCstring & line );
    
    const list<NCstring> & Text() const { return mtext; }
    const NCstring &       operator[]( std::wstring::size_type idx ) const;

    const_iterator begin() const { return mtext.begin(); }
    const_iterator end()   const { return mtext.end(); }
};

///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : NClabel
//
//	DESCRIPTION :
//
class NClabel : protected NCtext {

  friend std::ostream & operator<<( std::ostream & STREAM, const NClabel & OBJ );

  protected:

    std::wstring::size_type hotline;

    virtual void lset( const NCstring & ntext ) {
      NCtext::lset( ntext );
//      stripHotkey();
    }

  public:

    void stripHotkey();
    NClabel( const NCstring & nstr = "" )
      : NCtext( nstr )
    { /*stripHotkey();*/ }

    virtual ~NClabel() {}

  public:

    size_t   width()  const { return Columns(); }
    unsigned height() const { return Lines(); }
    wsze     size()   const { return wsze( Lines(), Columns() ); }
    const list<NCstring> & getText() const { return Text(); }
    
    void drawAt( NCursesWindow & w, chtype style, chtype hotstyle,
		 const wrect & dim,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const;

    //
    void drawAt( NCursesWindow & w, chtype style, chtype hotstyle,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const {
      drawAt( w, style, hotstyle, wrect( 0, -1 ), adjust, fillup );
    }

    void drawAt( NCursesWindow & w, chtype style, chtype hotstyle,
		 const wpos & pos,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const {
      drawAt( w, style, hotstyle, wrect( pos, -1 ), adjust, fillup );
    }

    void drawAt( NCursesWindow & w, chtype style, chtype hotstyle,
		 const wpos & pos, const wsze & sze,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const {
      drawAt( w, style, hotstyle, wrect( pos, sze ), adjust, fillup );
    }

    //
    void drawAt( NCursesWindow & w, const NCstyle::StItem & istyle,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const {
      drawAt( w, istyle.label, istyle.hint, wrect( 0, -1 ), adjust, fillup );
    }

    void drawAt( NCursesWindow & w, const NCstyle::StItem & istyle,
		 const wpos & pos,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const {
      drawAt( w, istyle.label, istyle.hint, wrect( pos, -1 ), adjust, fillup );
    }

    void drawAt( NCursesWindow & w, const NCstyle::StItem & istyle,
		 const wpos & pos, const wsze & sze,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const {
      drawAt( w, istyle.label, istyle.hint, wrect( pos, sze ), adjust, fillup );
    }

    void drawAt( NCursesWindow & w, const NCstyle::StItem & istyle,
		 const wrect & dim,
		 const NC::ADJUST adjust = NC::TOPLEFT,
		 bool fillup = true ) const {
      drawAt( w, istyle.label, istyle.hint, dim, adjust, fillup );
    }

    //


    bool        hasHotkey() const { return hotline != wstring::npos; }
    wchar_t 	hotkey() const { return hasHotkey() ? operator[]( hotline ).hotkey() : L'\0'; }
    std::wstring::size_type   hotpos() const { return hasHotkey() ? operator[]( hotline ).hotpos() : wstring::npos; }
};

///////////////////////////////////////////////////////////////////

#endif // NCtext_h