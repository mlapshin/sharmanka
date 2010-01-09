#include "shr/Prerequisites.hpp"
#include "shr/Application.hpp"
#include "shr/gui/MainWindow.hpp"

IMPLEMENT_APP(shr::Application)

namespace shr
{

bool Application::OnInit()
{
  wxInitAllImageHandlers(); // TODO: we need only PNG here

  m_main_window = new gui::MainWindow;
  SetTopWindow(m_main_window);
  m_main_window->Show(true);
  return true;
}

}
