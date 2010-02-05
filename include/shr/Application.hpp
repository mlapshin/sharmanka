#ifndef _APPLICATION_H_
#define _APPLICATION_H_

namespace shr
{

class TrackList;
namespace gui
{
  class MainWindow;
  class TrayIcon;
  class AboutDialog;
}

class Application : public wxApp
{
 public:

  inline const wxString& GetSid() const {
    return m_sid;
  }

  void ShowAboutDialog();
  void Exit();

  inline TrackList* GetTrackList()
  {
    return m_tracks;
  }

 private:

  virtual bool OnInit();
  virtual int OnExit();

  gui::MainWindow* m_main_window;
  gui::AboutDialog* m_about;
  gui::TrayIcon* m_tray_icon;
  TrackList* m_tracks;
  wxString m_sid;
};

};

DECLARE_APP(shr::Application)

#endif /* _APPLICATION_H_ */
