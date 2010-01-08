#include "wx/wxprec.h"
#ifndef WX_PRECOMP
# include "wx/wx.h"
#endif

#include "wx/frame.h"


class MyApp: public wxApp
{
  virtual bool OnInit();
};

DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)

class MainFrame: public wxFrame // MainFrame is the class for our window
{
public:
  MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
: wxFrame((wxFrame *) NULL, -1, title, pos, size) 
{
  // normally we would initialize objects such as buttons and textboxes here 
}

bool MyApp::OnInit()
{
  wxFrame *frame = new MainFrame(_("Апроач ту какроач"), wxDefaultPosition, wxSize(300, 200));
  frame->CreateStatusBar();
  frame->SetStatusText(_T("Hello World"));
  frame->Show(true);
  SetTopWindow(frame);
  return true;
}
