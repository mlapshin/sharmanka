#ifndef _APPLICATION_H_
#define _APPLICATION_H_

namespace shr
{

namespace gui { class MainWindow; class TrayIcon; }

class MainWindow;

class Application : public wxApp
{
 public:

  inline const wxString& GetSid() const {
    return m_sid;
  }

 private:

  virtual bool OnInit();

  gui::MainWindow* m_main_window;
  gui::TrayIcon* m_tray_icon;
  wxString m_sid;
};

};

DECLARE_APP(shr::Application)

#endif /* _APPLICATION_H_ */
