#include "shr/Prerequisites.hpp"
#include "shr/gui/MainWindow.hpp"

#include "shr/TrackSearchThread.hpp"
#include "shr/gui/TrackList.hpp"

namespace shr
{
namespace gui
{

BEGIN_EVENT_TABLE(MainWindow, MainWindowBase)
  EVT_CLOSE(MainWindow::OnClose)
END_EVENT_TABLE()


MainWindow::MainWindow()
  : MainWindowBase(NULL)
{
  Connect(TSE_COMPLETED, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnTrackSearchCompleted) );
  Connect(TSE_ERROR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnTrackSearchError) );
  Connect(TSE_PULSE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainWindow::OnTrackSearchPulse) );

  SetQueryPlaceholder();
}

MainWindow::~MainWindow()
{
  TerminateCurrentSearch();
}

void MainWindow::TerminateCurrentSearch()
{
  if (m_trackSearchThread != 0) {
    m_trackSearchThread->Delete(); // wait for thread
    delete m_trackSearchThread;
    m_trackSearchThread = 0;
    ShowSearchGauge(false);
  }
}

void MainWindow::OnQueryEnter( wxCommandEvent& event )
{
  if (m_query->GetValue() != _T("")) {
    TerminateCurrentSearch();

    m_trackSearchThread = new TrackSearchThread(this, m_query->GetValue(), 0);
    m_trackSearchThread->Run();
    ShowSearchGauge(true);
  }
}

void MainWindow::OnQueryFocus( wxFocusEvent& event )
{
  if (m_queryPlaceholder) {
    RemoveQueryPlaceholder();
  }
}

void MainWindow::OnQueryUnfocus( wxFocusEvent& event )
{
  if (m_query->GetValue().Trim().Length() == 0) {
    SetQueryPlaceholder();
  }
}

void MainWindow::OnTrackSearchError( wxCommandEvent& event )
{
  wxMessageBox(_T("HTTP Error"));
  TerminateCurrentSearch();
}

void MainWindow::SetQueryPlaceholder()
{
  m_query->SetValue(_T("Введите название песни или исполнителя и нажмите \"Enter\""));
  m_query->SetForegroundColour(*wxLIGHT_GREY);
  m_queryPlaceholder = true;
}

void MainWindow::RemoveQueryPlaceholder()
{
  if (m_queryPlaceholder)
  {
    m_queryPlaceholder = false;
    m_query->SetValue(_T(""));
    m_query->SetForegroundColour(wxNullColour);
  }
}


void MainWindow::OnTrackSearchCompleted( wxCommandEvent& event )
{
  m_trackList->SetTracks(m_trackSearchThread->GetTracks());
  m_searchGauge->Show(false);
}

void MainWindow::OnTrackSearchPulse( wxCommandEvent& event )
{
  if(event.GetInt() > 0) {
    m_searchGauge->SetValue(event.GetInt());
  } else {
    m_searchGauge->Pulse();
  }
}

void MainWindow::ShowSearchGauge(bool show)
{
  m_searchSizer->Show(m_searchGauge, show);
  m_searchSizer->Layout();
}

void MainWindow::OnClose(wxCloseEvent& e)
{
  if (e.CanVeto()) {
    Show(false);
  } else {
    TerminateCurrentSearch();
    Destroy();
  }
}

}}
