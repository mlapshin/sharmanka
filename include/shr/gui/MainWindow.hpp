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

  virtual void OnSearchButtonClick( wxCommandEvent& event );

  void OnTrackSearchError( wxCommandEvent& event );
  void OnTrackSearchCompleted( wxCommandEvent& event );

 private:
  TrackSearchThread* m_trackSearchThread;

  void TerminateCurrentSearch();
};

}
}

#endif /* _MAINWINDOW_H_ */
