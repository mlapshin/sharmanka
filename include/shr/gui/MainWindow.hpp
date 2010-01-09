#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "_shr_gui.h"

namespace shr
{
namespace gui
{

class MainWindow: public MainWindowBase
{
 public:
  MainWindow();

  virtual void foo( wxCommandEvent& event );
};

}
}

#endif /* _MAINWINDOW_H_ */
