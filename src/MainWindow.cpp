#include "shr/Prerequisites.hpp"
#include "shr/gui/MainWindow.hpp"

namespace shr
{
namespace gui
{

MainWindow::MainWindow()
  : MainWindowBase(NULL)
{
  /*
  wxTextAttr normalStyle = m_songTitle->GetDefaultStyle();
  wxTextAttr boldStyle = wxTextAttr(wxNullColour, wxNullColour, wxFont(normalStyle.GetFont().GetPointSize(),
                                                                       normalStyle.GetFont().GetFamily(),
                                                                       normalStyle.GetFont().GetStyle(),
                                                                       wxFONTWEIGHT_BOLD));

  wxTextAttr italicStyle = wxTextAttr(wxNullColour, wxNullColour, wxFont(normalStyle.GetFont().GetPointSize(),
                                                                         normalStyle.GetFont().GetFamily(),
                                                                         wxFONTSTYLE_ITALIC,
                                                                         normalStyle.GetFont().GetWeight()));


  m_songTitle->Clear();
  m_songTitle->SetDefaultStyle(boldStyle);
  m_songTitle->AppendText(_T("Безмозглые программистишки"));
  m_songTitle->SetDefaultStyle(normalStyle);
  m_songTitle->AppendText(_T(" — "));
  m_songTitle->SetDefaultStyle(italicStyle);
  m_songTitle->AppendText(_T("Велосипед, зеркалка, классные проекты"));
  */

  m_songTitle->SetBorders(0);
  m_songTitle->SetPage(_T("<font size='+1'><b>Белая горячка</b></font> &mdash; <i>Трогательные ножечки</i>"));
  m_songTitle->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
}

void MainWindow::foo( wxCommandEvent& event ) {
  m_songTitle->SetScrollbar(wxVERTICAL, 0, 0, 50);
}

}
}
