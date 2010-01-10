#ifndef _TRACKLIST_H_
#define _TRACKLIST_H_

#include "wx/htmllbox.h"

namespace shr {
namespace gui {

class TrackList : public wxHtmlListBox
{
 public:
  TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& s = wxDefaultSize, long unused_arg = 0); // TODO: remove unused style arg
  ~TrackList();

 protected:
  virtual wxString OnGetItem(size_t n) const;
};

}}

#endif /* _TRACKLIST_H_ */
