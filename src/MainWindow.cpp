#include "shr/Prerequisites.hpp"
#include "shr/MainWindow.hpp"

namespace shr
{

MainWindow::MainWindow()
  : wxFrame(NULL, -1, _T("Шарманка"), wxDefaultPosition, wxDefaultSize)
{
}

}