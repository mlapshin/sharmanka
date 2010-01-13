#ifndef _TRACKSEARCHTHREAD_H_
#define _TRACKSEARCHTHREAD_H_

#include "wx/thread.h"
#include "shr/Track.hpp"

namespace shr
{

// Trach Search Events
enum {
  TSE_COMPLETED,
  TSE_ERROR,
  TSE_PULSE
};

class TrackSearchThread : public wxThread
{
 public:
  TrackSearchThread(wxEvtHandler* eventReceiver, const wxString& query, int offset = 0);

  inline const TrackVector& GetTracks() const
  {
    return m_tracks;
  }

  inline long GetTotalTracksCount() const
  {
    return m_totalTracks;
  }

 private:
  TrackVector m_tracks;
  wxEvtHandler* m_eventReceiver;
  wxString m_query;
  int m_offset;
  long m_totalTracks;

  virtual void* Entry();
  void Pulse(int prgrs = 0);
  Track GetTrackFromAudioRow(const wxString& ar);

  wxString GetPage(const wxString& path);
};

}

#endif /* _TRACKSEARCHTHREAD_H_ */
