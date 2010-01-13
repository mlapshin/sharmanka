#include "shr/Prerequisites.hpp"
#include "shr/Application.hpp"
#include "shr/gui/MainWindow.hpp"
#include "shr/gui/TrayIcon.hpp"
#include "wx/xrc/xmlres.h"

IMPLEMENT_APP(shr::Application)

extern void InitXmlResource();

namespace shr
{

bool Application::OnInit()
{
  wxImage::AddHandler(new wxPNGHandler);
  wxXmlResource::Get()->InitAllHandlers();
  InitXmlResource();

  m_main_window = new gui::MainWindow;
  m_tray_icon = new gui::TrayIcon(m_main_window);

  SetTopWindow(m_main_window);
  m_main_window->Show(true);


  m_sid = argv[1];

  return true;
}

void Application::Exit()
{
  delete m_tray_icon;
  m_main_window->Destroy();
}

int Application::OnExit()
{
}

}
