#ifndef _TRAYICON_H_
#define _TRAYICON_H_

#include "wx/taskbar.h"

namespace shr
{
namespace gui
{

class MainWindow;

enum {
  TI_EXIT
};

class TrayIcon : public wxTaskBarIcon
{
 public:
  TrayIcon(MainWindow* mw);

 protected:
  MainWindow* m_mainWindow;
  virtual wxMenu *CreatePopupMenu();

  void OnLeftClick(wxTaskBarIconEvent& event);
  void OnMenuExitClick(wxCommandEvent& event);

  DECLARE_EVENT_TABLE()
};

}
}

#endif /* _TRAYICON_H_ */
