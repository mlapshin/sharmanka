#include "shr/Prerequisites.hpp"
#include "shr/gui/MainWindow.hpp"

#include "shr/TrackSearchThread.hpp"

namespace shr
{
namespace gui
{

MainWindow::MainWindow()
  : MainWindowBase(NULL)
{
  m_songTitle->SetBorders(0);
  m_songTitle->SetPage(_T("<font size='+1'><b>Белая горячка</b></font> &mdash; <i>Трогательные ножечки</i>"));
  m_songTitle->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));

  m_trackSearchThread = new TrackSearchThread(this);
  Connect(TSE_COMPLETED, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnTrackSearchCompleted) );
  Connect(TSE_ERROR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnTrackSearchError) );
}

MainWindow::~MainWindow()
{
  delete m_trackSearchThread;
}

void MainWindow::OnSearchButtonClick( wxCommandEvent& event )
{
  m_trackSearchThread->Run();
}

void MainWindow::OnTrackSearchError( wxCommandEvent& event )
{
  wxMessageBox(_T("HTTP Error"));
}

void MainWindow::OnTrackSearchCompleted( wxCommandEvent& event )
{
  wxString t;
  t.Printf(_T("%d"), event.GetInt());
  wxMessageBox(t + _T(":\n\n") + event.GetString().Mid(0, 10));
}


}}
