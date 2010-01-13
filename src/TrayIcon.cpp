#include "shr/Prerequisites.hpp"
#include "shr/gui/TrayIcon.hpp"

namespace shr {
namespace gui {

BEGIN_EVENT_TABLE(TrayIcon, wxTaskBarIcon)
END_EVENT_TABLE()

TrayIcon::TrayIcon()
{
  SetIcon(wxIcon(_T("bitmaps/icons/control.png")));
}

wxMenu* TrayIcon::CreatePopupMenu()
{
  wxMenu *menu = new wxMenu;
  menu->Append(-1, _T("Hello world!"));

  return menu;
}

}}
