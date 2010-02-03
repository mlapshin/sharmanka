#include "shr/Prerequisites.hpp"
#include "shr/gui/AboutDialog.hpp"

#define ABOUT_HTML "" \
  "<html><body><center>" \
  "<img src='bitmaps/big_logo.png' ><br>" \
  "<font size=+3><b>Шарманка 0.1</b></font><br>" \
  "<font size=-1>A Savage Journey to the Heart of the Open-Source Dream</font>" \
  "<p><a href='http://sharmanka.sotakone.com'>http://sharmanka.sotakone.com</a>" \
  "</center></body></html>"

namespace shr
{
namespace gui
{

AboutDialog::AboutDialog(wxWindow* parent)
    : AboutDialogBase(parent)
{
  m_html->SetPage(_T(ABOUT_HTML));
  m_html->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWFRAME ) );
}


} } // namespace shr::gui
