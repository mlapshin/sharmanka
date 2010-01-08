#ifndef _APPLICATION_H_
#define _APPLICATION_H_

namespace shr
{

namespace gui { class MainWindow; }

class MainWindow;

class Application : public wxApp
{
 private:

  virtual bool OnInit();

  gui::MainWindow* m_main_window;
};

};

DECLARE_APP(shr::Application)

#endif /* _APPLICATION_H_ */
