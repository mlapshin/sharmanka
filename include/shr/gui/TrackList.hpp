#ifndef _TRACKLIST_H_
#define _TRACKLIST_H_

#include "wx/listctrl.h"

namespace shr {
namespace gui {

class TrackList : public wxListCtrl
{
 public:
  TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& s = wxDefaultSize, long style = 0); // TODO: remove unused style arg
  ~TrackList();
};

}}

#endif /* _TRACKLIST_H_ */
