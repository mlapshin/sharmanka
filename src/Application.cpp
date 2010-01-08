#include "shr/Prerequisites.hpp"
#include "shr/Application.hpp"
#include "shr/MainWindow.hpp"

IMPLEMENT_APP(shr::Application)

namespace shr
{

bool Application::OnInit()
{
  wxFrame *frame = new MainWindow;
  frame->CreateStatusBar();
  frame->SetStatusText(_T("Hello World"));
  frame->Show(true);
  SetTopWindow(frame);
  return true;
}

}
