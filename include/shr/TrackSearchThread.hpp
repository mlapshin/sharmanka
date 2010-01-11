#ifndef _TRACKSEARCHTHREAD_H_
#define _TRACKSEARCHTHREAD_H_

#include "wx/thread.h"

namespace shr
{

// Trach Search Events
enum {
  TSE_COMPLETED,
  TSE_ERROR
};

class TrackSearchThread : public wxThread
{
 public:
  TrackSearchThread(wxEvtHandler* eventReceiver);

 private:
  wxEvtHandler* m_eventReceiver;
  virtual void* Entry();

  wxString GetPage(const wxString& path);
};

}

#endif /* _TRACKSEARCHTHREAD_H_ */
