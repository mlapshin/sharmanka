#include "shr/Prerequisites.hpp"
#include "shr/Application.hpp"
#include "shr/gui/MainWindow.hpp"
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
  SetTopWindow(m_main_window);
  m_main_window->Show(true);
  return true;
}

}
