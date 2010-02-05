#ifndef _PREREQUISITES_H_
#define _PREREQUISITES_H_

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include <iostream>
#include <vector>
#include <list>

#define SHARMANKA_USER_AGENT _T("Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.1.6) Gecko/20091215 Ubuntu/9.10 (karmic) Firefox/3.5.6")

// Event identifiers
enum {
  // TrackList
  TLE_MOAR_TRACKS,

  // TrackSearchThread
  TSE_COMPLETED,
  TSE_ERROR,
  TSE_PULSE
};


#endif /* _PREREQUISITES_H_ */
