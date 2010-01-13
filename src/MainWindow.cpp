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
    RunQuery(new TrackSearchThread(this, m_query->GetValue(), 0));
  }
}

void MainWindow::RunQuery(TrackSearchThread* q)
{
  TerminateCurrentSearch();

  m_trackSearchThread = q;
  m_trackSearchThread->Run();
  ShowSearchGauge(true);
}

void MainWindow::QueryMoreTracks()
{
  TrackSearchThread* newSearch = new TrackSearchThread(this,
                                                       m_trackSearchThread->GetQuery(),
                                                       m_trackSearchThread->GetOffset() + 100);

  RunQuery(newSearch);
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
  wxString counter;

  if (m_trackSearchThread->GetOffset() > 0) {
    m_trackList->AppendTracks(m_trackSearchThread->GetTracks());
  } else {
    m_trackList->SetTracks(m_trackSearchThread->GetTracks());
  }

  counter.Printf(_T("%d / %d"), m_trackList->GetTracks().size(), m_trackSearchThread->GetTotalTracksCount());
  m_tracksCount->SetLabel(counter);
  ShowSearchGauge(false);
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
  if (show) {
    m_searchSizer->Show(m_searchGauge, true);
    m_searchSizer->Show(m_tracksCount, false);
  } else {
    m_searchSizer->Show(m_searchGauge, false);
    m_searchSizer->Show(m_tracksCount, true);
  }

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
