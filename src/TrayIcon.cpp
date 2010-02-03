#include "shr/Prerequisites.hpp"
#include "shr/gui/TrayIcon.hpp"
#include "shr/gui/MainWindow.hpp"
#include "shr/Application.hpp"

namespace shr {
namespace gui {

BEGIN_EVENT_TABLE(TrayIcon, wxTaskBarIcon)

EVT_TASKBAR_LEFT_DOWN(TrayIcon::OnLeftClick)
EVT_MENU(TI_EXIT, TrayIcon::OnMenuExitClick)
EVT_MENU(TI_ABOUT, TrayIcon::OnMenuAboutClick)

END_EVENT_TABLE()

TrayIcon::TrayIcon(MainWindow* mw)
    : m_mainWindow(mw)
{
  SetIcon(wxIcon(_T("bitmaps/icons/tray-idle.gif")));
}

wxMenu* TrayIcon::CreatePopupMenu()
{
  wxMenu *menu = new wxMenu;
  menu->Append(TI_ABOUT, _T("О программе"));
  menu->AppendSeparator();
  menu->Append(TI_EXIT, _T("Выход"));

  return menu;
}

void TrayIcon::OnLeftClick(wxTaskBarIconEvent& event)
{
  // TODO: move it inside Application class
  m_mainWindow->Show(!m_mainWindow->IsShown());
}

void TrayIcon::OnMenuExitClick(wxCommandEvent& e)
{
  wxGetApp().Exit();
}

void TrayIcon::OnMenuAboutClick(wxCommandEvent& e)
{
  wxGetApp().ShowAboutDialog();
}

}}
