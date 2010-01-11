#ifndef _APPLICATION_H_
#define _APPLICATION_H_

namespace shr
{

namespace gui { class MainWindow; }

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
  wxString m_sid;
};

};

DECLARE_APP(shr::Application)

#endif /* _APPLICATION_H_ */
