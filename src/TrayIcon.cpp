#include "shr/Prerequisites.hpp"
#include "shr/gui/TrayIcon.hpp"
#include "shr/gui/MainWindow.hpp"
#include "shr/Application.hpp"

namespace shr {
namespace gui {

BEGIN_EVENT_TABLE(TrayIcon, wxTaskBarIcon)

EVT_TASKBAR_LEFT_DOWN(TrayIcon::OnLeftClick)
EVT_MENU(TI_EXIT, TrayIcon::OnMenuExitClick)

END_EVENT_TABLE()

TrayIcon::TrayIcon(MainWindow* mw)
    : m_mainWindow(mw)
{
  SetIcon(wxIcon(_T("bitmaps/icons/tray-paused.gif")));
}

wxMenu* TrayIcon::CreatePopupMenu()
{
  wxMenu *menu = new wxMenu;
  menu->Append(-1, _T("Hello world!"));
  menu->AppendSeparator();
  menu->Append(TI_EXIT, _T("Выход"));

  return menu;
}

void TrayIcon::OnLeftClick(wxTaskBarIconEvent& event)
{
  m_mainWindow->Show(!m_mainWindow->IsShown());
}

void TrayIcon::OnMenuExitClick(wxCommandEvent& e)
{
  wxGetApp().Exit();
}

}}
