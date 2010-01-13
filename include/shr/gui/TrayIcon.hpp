#ifndef _TRAYICON_H_
#define _TRAYICON_H_

#include "wx/taskbar.h"

namespace shr
{
namespace gui
{

class TrayIcon : public wxTaskBarIcon
{
 public:
  TrayIcon();

 protected:
  virtual wxMenu *CreatePopupMenu();

  DECLARE_EVENT_TABLE()
};

}
}

#endif /* _TRAYICON_H_ */
