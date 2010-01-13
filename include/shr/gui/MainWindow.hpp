#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "_shr_gui.h"

namespace shr
{

class TrackSearchThread;

namespace gui
{

class MainWindow: public MainWindowBase
{
 public:
  MainWindow();
  ~MainWindow();

  void OnQueryEnter( wxCommandEvent& event );
  void OnQueryFocus( wxFocusEvent& event );
  void OnQueryUnfocus( wxFocusEvent& event );

  void OnTrackSearchError( wxCommandEvent& event );
  void OnTrackSearchPulse( wxCommandEvent& event );
  void OnTrackSearchCompleted( wxCommandEvent& event );

  void OnClose(wxCloseEvent& e);

 private:
  TrackSearchThread* m_trackSearchThread;

  bool m_queryPlaceholder;
  void SetQueryPlaceholder();
  void RemoveQueryPlaceholder();

  void TerminateCurrentSearch();

  void ShowSearchGauge(bool show);

  DECLARE_EVENT_TABLE()
};

}
}

#endif /* _MAINWINDOW_H_ */
