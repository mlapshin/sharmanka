#ifndef _TRACKLIST_H_
#define _TRACKLIST_H_

#include "wx/htmllbox.h"
#include "shr/Track.hpp"
#include <vector>

namespace shr {
namespace gui {

class TrackList : public wxHtmlListBox
{
 public:
  TrackList(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& s = wxDefaultSize, long unused_arg = 0); // TODO: remove unused style arg
  ~TrackList();

  void SetTracks(const TrackVector& newTracks);
  void OnDrawBackground(wxDC& dc, const wxRect& rect, size_t n) const;

 protected:
  virtual wxString OnGetItem(size_t n) const;
  TrackVector m_tracks;
};

}}

#endif /* _TRACKLIST_H_ */
