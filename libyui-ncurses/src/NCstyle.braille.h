/*
  Copyright (C) 1970-2012 Novell, Inc
  This library is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation; either version 2.1 of the
  License, or (at your option) version 3.0 of the License. This library
  is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or 
  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
  License for more details. You should have received a copy of the GNU
  Lesser General Public License along with this library; if not, write
  to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
  Floor, Boston, MA 02110-1301 USA
*/


/*-/

   File:       NCstyle.braille.h

   Author:     Generated by class NCstyle

/-*/

#ifndef NCstyle_braille_h
#define NCstyle_braille_h

#include "NCstyle.h"

inline void NCstyleInit_braille( std::vector<NCstyle::Style> & styleSet )
{
    //=================================================================
    // init global attributes
    //=================================================================
    NCattrset * attrset( &styleSet[NCstyle::DefaultStyle].getAttrGlobal() );
    attrset->setAttr( NCstyle::AppTitle, 14080 );
    attrset->setAttr( NCstyle::AppText, 8192 );
    //=================================================================
    // init local attributes
    //=================================================================
    // DefaultStyle
    attrset = &styleSet[NCstyle::DefaultStyle].getAttrLocal();
    attrset->setAttr( NCstyle::DialogBorder, 8192 );
    attrset->setAttr( NCstyle::DialogTitle, 8192 );
    attrset->setAttr( NCstyle::DialogActiveBorder, 13056 );
    attrset->setAttr( NCstyle::DialogActiveTitle, 13056 );
    attrset->setAttr( NCstyle::DialogText, 8192 );
    attrset->setAttr( NCstyle::DialogHeadline, 8192 );
    attrset->setAttr( NCstyle::DialogDisabled, 8448 );
    attrset->setAttr( NCstyle::DialogPlain, 8192 );
    attrset->setAttr( NCstyle::DialogLabel, 8192 );
    attrset->setAttr( NCstyle::DialogData, 9216 );
    attrset->setAttr( NCstyle::DialogHint, 9728 );
    attrset->setAttr( NCstyle::DialogScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActivePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveScrl, 13568 );
    attrset->setAttr( NCstyle::DialogFramePlain, 8192 );
    attrset->setAttr( NCstyle::DialogFrameLabel, 8192 );
    attrset->setAttr( NCstyle::DialogFrameData, 9216 );
    attrset->setAttr( NCstyle::DialogFrameHint, 9728 );
    attrset->setAttr( NCstyle::DialogFrameScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActiveFramePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveFrameHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveFrameScrl, 13568 );
    attrset->setAttr( NCstyle::ListTitle, 8192 );
    attrset->setAttr( NCstyle::ListPlain, 8192 );
    attrset->setAttr( NCstyle::ListLabel, 8192 );
    attrset->setAttr( NCstyle::ListData, 9216 );
    attrset->setAttr( NCstyle::ListHint, 9472 );
    attrset->setAttr( NCstyle::ListSelPlain, 8192 );
    attrset->setAttr( NCstyle::ListSelLabel, 8192 );
    attrset->setAttr( NCstyle::ListSelData, 9216 );
    attrset->setAttr( NCstyle::ListSelHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveTitle, 8192 );
    attrset->setAttr( NCstyle::ListActivePlain, 8192 );
    attrset->setAttr( NCstyle::ListActiveLabel, 8192 );
    attrset->setAttr( NCstyle::ListActiveData, 9216 );
    attrset->setAttr( NCstyle::ListActiveHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveSelPlain, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelLabel, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelData, 13312 );
    attrset->setAttr( NCstyle::ListActiveSelHint, 13568 );
    attrset->setAttr( NCstyle::RichTextPlain, 8192 );
    attrset->setAttr( NCstyle::RichTextTitle, 8192 );
    attrset->setAttr( NCstyle::RichTextLink, 8192 );
    attrset->setAttr( NCstyle::RichTextArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextActiveArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextVisitedLink, 0 );
    attrset->setAttr( NCstyle::RichTextB, 8192 );
    attrset->setAttr( NCstyle::RichTextI, 8192 );
    attrset->setAttr( NCstyle::RichTextT, 8192 );
    attrset->setAttr( NCstyle::RichTextBI, 8192 );
    attrset->setAttr( NCstyle::RichTextBT, 8192 );
    attrset->setAttr( NCstyle::RichTextIT, 8192 );
    attrset->setAttr( NCstyle::RichTextBIT, 8192 );
    attrset->setAttr( NCstyle::ProgbarCh, 16128 );
    attrset->setAttr( NCstyle::ProgbarBgch, 4194481 );
    attrset->setAttr( NCstyle::TextCursor, 2048 );
    // InfoStyle
    attrset = &styleSet[NCstyle::InfoStyle].getAttrLocal();
    attrset->setAttr( NCstyle::DialogBorder, 9472 );
    attrset->setAttr( NCstyle::DialogTitle, 9472 );
    attrset->setAttr( NCstyle::DialogActiveBorder, 4864 );
    attrset->setAttr( NCstyle::DialogActiveTitle, 4864 );
    attrset->setAttr( NCstyle::DialogText, 8192 );
    attrset->setAttr( NCstyle::DialogHeadline, 8192 );
    attrset->setAttr( NCstyle::DialogDisabled, 8448 );
    attrset->setAttr( NCstyle::DialogPlain, 8192 );
    attrset->setAttr( NCstyle::DialogLabel, 8192 );
    attrset->setAttr( NCstyle::DialogData, 9216 );
    attrset->setAttr( NCstyle::DialogHint, 9728 );
    attrset->setAttr( NCstyle::DialogScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActivePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveScrl, 13568 );
    attrset->setAttr( NCstyle::DialogFramePlain, 8192 );
    attrset->setAttr( NCstyle::DialogFrameLabel, 8192 );
    attrset->setAttr( NCstyle::DialogFrameData, 9216 );
    attrset->setAttr( NCstyle::DialogFrameHint, 9728 );
    attrset->setAttr( NCstyle::DialogFrameScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActiveFramePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveFrameHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveFrameScrl, 13568 );
    attrset->setAttr( NCstyle::ListTitle, 8192 );
    attrset->setAttr( NCstyle::ListPlain, 8192 );
    attrset->setAttr( NCstyle::ListLabel, 8192 );
    attrset->setAttr( NCstyle::ListData, 9216 );
    attrset->setAttr( NCstyle::ListHint, 9472 );
    attrset->setAttr( NCstyle::ListSelPlain, 8192 );
    attrset->setAttr( NCstyle::ListSelLabel, 8192 );
    attrset->setAttr( NCstyle::ListSelData, 9216 );
    attrset->setAttr( NCstyle::ListSelHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveTitle, 8192 );
    attrset->setAttr( NCstyle::ListActivePlain, 8192 );
    attrset->setAttr( NCstyle::ListActiveLabel, 8192 );
    attrset->setAttr( NCstyle::ListActiveData, 9216 );
    attrset->setAttr( NCstyle::ListActiveHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveSelPlain, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelLabel, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelData, 13312 );
    attrset->setAttr( NCstyle::ListActiveSelHint, 13568 );
    attrset->setAttr( NCstyle::RichTextPlain, 8192 );
    attrset->setAttr( NCstyle::RichTextTitle, 8192 );
    attrset->setAttr( NCstyle::RichTextLink, 8192 );
    attrset->setAttr( NCstyle::RichTextArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextActiveArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextVisitedLink, 0 );
    attrset->setAttr( NCstyle::RichTextB, 8192 );
    attrset->setAttr( NCstyle::RichTextI, 8192 );
    attrset->setAttr( NCstyle::RichTextT, 8192 );
    attrset->setAttr( NCstyle::RichTextBI, 8192 );
    attrset->setAttr( NCstyle::RichTextBT, 8192 );
    attrset->setAttr( NCstyle::RichTextIT, 8192 );
    attrset->setAttr( NCstyle::RichTextBIT, 8192 );
    attrset->setAttr( NCstyle::ProgbarCh, 16128 );
    attrset->setAttr( NCstyle::ProgbarBgch, 4194481 );
    attrset->setAttr( NCstyle::TextCursor, 2048 );
    // WarnStyle
    attrset = &styleSet[NCstyle::WarnStyle].getAttrLocal();
    attrset->setAttr( NCstyle::DialogBorder, 9728 );
    attrset->setAttr( NCstyle::DialogTitle, 9728 );
    attrset->setAttr( NCstyle::DialogActiveBorder, 2816 );
    attrset->setAttr( NCstyle::DialogActiveTitle, 2816 );
    attrset->setAttr( NCstyle::DialogText, 8192 );
    attrset->setAttr( NCstyle::DialogHeadline, 8192 );
    attrset->setAttr( NCstyle::DialogDisabled, 8448 );
    attrset->setAttr( NCstyle::DialogPlain, 8192 );
    attrset->setAttr( NCstyle::DialogLabel, 8192 );
    attrset->setAttr( NCstyle::DialogData, 9216 );
    attrset->setAttr( NCstyle::DialogHint, 9728 );
    attrset->setAttr( NCstyle::DialogScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActivePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveScrl, 13568 );
    attrset->setAttr( NCstyle::DialogFramePlain, 8192 );
    attrset->setAttr( NCstyle::DialogFrameLabel, 8192 );
    attrset->setAttr( NCstyle::DialogFrameData, 9216 );
    attrset->setAttr( NCstyle::DialogFrameHint, 9728 );
    attrset->setAttr( NCstyle::DialogFrameScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActiveFramePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveFrameHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveFrameScrl, 13568 );
    attrset->setAttr( NCstyle::ListTitle, 8192 );
    attrset->setAttr( NCstyle::ListPlain, 8192 );
    attrset->setAttr( NCstyle::ListLabel, 8192 );
    attrset->setAttr( NCstyle::ListData, 9216 );
    attrset->setAttr( NCstyle::ListHint, 9472 );
    attrset->setAttr( NCstyle::ListSelPlain, 8192 );
    attrset->setAttr( NCstyle::ListSelLabel, 8192 );
    attrset->setAttr( NCstyle::ListSelData, 9216 );
    attrset->setAttr( NCstyle::ListSelHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveTitle, 8192 );
    attrset->setAttr( NCstyle::ListActivePlain, 8192 );
    attrset->setAttr( NCstyle::ListActiveLabel, 8192 );
    attrset->setAttr( NCstyle::ListActiveData, 9216 );
    attrset->setAttr( NCstyle::ListActiveHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveSelPlain, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelLabel, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelData, 13312 );
    attrset->setAttr( NCstyle::ListActiveSelHint, 13568 );
    attrset->setAttr( NCstyle::RichTextPlain, 8192 );
    attrset->setAttr( NCstyle::RichTextTitle, 8192 );
    attrset->setAttr( NCstyle::RichTextLink, 8192 );
    attrset->setAttr( NCstyle::RichTextArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextActiveArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextVisitedLink, 0 );
    attrset->setAttr( NCstyle::RichTextB, 8192 );
    attrset->setAttr( NCstyle::RichTextI, 8192 );
    attrset->setAttr( NCstyle::RichTextT, 8192 );
    attrset->setAttr( NCstyle::RichTextBI, 8192 );
    attrset->setAttr( NCstyle::RichTextBT, 8192 );
    attrset->setAttr( NCstyle::RichTextIT, 8192 );
    attrset->setAttr( NCstyle::RichTextBIT, 8192 );
    attrset->setAttr( NCstyle::ProgbarCh, 16128 );
    attrset->setAttr( NCstyle::ProgbarBgch, 4194481 );
    attrset->setAttr( NCstyle::TextCursor, 2048 );
    // PopupStyle
    attrset = &styleSet[NCstyle::PopupStyle].getAttrLocal();
    attrset->setAttr( NCstyle::DialogBorder, 8448 );
    attrset->setAttr( NCstyle::DialogTitle, 8448 );
    attrset->setAttr( NCstyle::DialogActiveBorder, 13056 );
    attrset->setAttr( NCstyle::DialogActiveTitle, 13056 );
    attrset->setAttr( NCstyle::DialogText, 8192 );
    attrset->setAttr( NCstyle::DialogHeadline, 8192 );
    attrset->setAttr( NCstyle::DialogDisabled, 8448 );
    attrset->setAttr( NCstyle::DialogPlain, 8192 );
    attrset->setAttr( NCstyle::DialogLabel, 8192 );
    attrset->setAttr( NCstyle::DialogData, 9216 );
    attrset->setAttr( NCstyle::DialogHint, 9728 );
    attrset->setAttr( NCstyle::DialogScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActivePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveScrl, 13568 );
    attrset->setAttr( NCstyle::DialogFramePlain, 8192 );
    attrset->setAttr( NCstyle::DialogFrameLabel, 8192 );
    attrset->setAttr( NCstyle::DialogFrameData, 9216 );
    attrset->setAttr( NCstyle::DialogFrameHint, 9728 );
    attrset->setAttr( NCstyle::DialogFrameScrl, 9472 );
    attrset->setAttr( NCstyle::DialogActiveFramePlain, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameLabel, 12288 );
    attrset->setAttr( NCstyle::DialogActiveFrameData, 13312 );
    attrset->setAttr( NCstyle::DialogActiveFrameHint, 13824 );
    attrset->setAttr( NCstyle::DialogActiveFrameScrl, 13568 );
    attrset->setAttr( NCstyle::ListTitle, 8192 );
    attrset->setAttr( NCstyle::ListPlain, 8192 );
    attrset->setAttr( NCstyle::ListLabel, 8192 );
    attrset->setAttr( NCstyle::ListData, 9216 );
    attrset->setAttr( NCstyle::ListHint, 9472 );
    attrset->setAttr( NCstyle::ListSelPlain, 8192 );
    attrset->setAttr( NCstyle::ListSelLabel, 8192 );
    attrset->setAttr( NCstyle::ListSelData, 9216 );
    attrset->setAttr( NCstyle::ListSelHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveTitle, 8192 );
    attrset->setAttr( NCstyle::ListActivePlain, 8192 );
    attrset->setAttr( NCstyle::ListActiveLabel, 8192 );
    attrset->setAttr( NCstyle::ListActiveData, 9216 );
    attrset->setAttr( NCstyle::ListActiveHint, 9472 );
    attrset->setAttr( NCstyle::ListActiveSelPlain, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelLabel, 12288 );
    attrset->setAttr( NCstyle::ListActiveSelData, 13312 );
    attrset->setAttr( NCstyle::ListActiveSelHint, 13568 );
    attrset->setAttr( NCstyle::RichTextPlain, 8192 );
    attrset->setAttr( NCstyle::RichTextTitle, 8192 );
    attrset->setAttr( NCstyle::RichTextLink, 8192 );
    attrset->setAttr( NCstyle::RichTextArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextActiveArmedlink, 8192 );
    attrset->setAttr( NCstyle::RichTextVisitedLink, 0 );
    attrset->setAttr( NCstyle::RichTextB, 8192 );
    attrset->setAttr( NCstyle::RichTextI, 8192 );
    attrset->setAttr( NCstyle::RichTextT, 8192 );
    attrset->setAttr( NCstyle::RichTextBI, 8192 );
    attrset->setAttr( NCstyle::RichTextBT, 8192 );
    attrset->setAttr( NCstyle::RichTextIT, 8192 );
    attrset->setAttr( NCstyle::RichTextBIT, 8192 );
    attrset->setAttr( NCstyle::ProgbarCh, 16128 );
    attrset->setAttr( NCstyle::ProgbarBgch, 4194481 );
    attrset->setAttr( NCstyle::TextCursor, 2048 );
}

#endif // NCstyle_braille_h
