///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "shr/gui/TrackListCtrl.hpp"

#include "_shr_gui.h"

///////////////////////////////////////////////////////////////////////////
using namespace shr::gui;

MainWindowBase::MainWindowBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxSize( 200,300 ), wxDefaultSize );
	
	wxBoxSizer* bSizer;
	bSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxT("Отходняки не шутка"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxNO_BORDER );
	m_textCtrl3->SetFont( wxFont( 11, 74, 90, 92, false, wxT("Sans") ) );
	m_textCtrl3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWFRAME ) );
	
	bSizer7->Add( m_textCtrl3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl4 = new wxTextCtrl( this, wxID_ANY, wxT("Гражданская Оборона"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxNO_BORDER );
	m_textCtrl4->SetFont( wxFont( 10, 74, 93, 90, false, wxT("Sans") ) );
	m_textCtrl4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWFRAME ) );
	
	bSizer8->Add( m_textCtrl4, 1, wxEXPAND, 5 );
	
	m_currentPos = new wxStaticText( this, wxID_ANY, wxT("0:40"), wxDefaultPosition, wxDefaultSize, 0 );
	m_currentPos->Wrap( -1 );
	m_currentPos->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Sans") ) );
	
	bSizer8->Add( m_currentPos, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );
	
	m_totalDuration = new wxStaticText( this, wxID_ANY, wxT(" / 3:34"), wxDefaultPosition, wxDefaultSize, 0 );
	m_totalDuration->Wrap( -1 );
	m_totalDuration->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Sans") ) );
	
	bSizer8->Add( m_totalDuration, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );
	
	bSizer7->Add( bSizer8, 1, wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	bSizer10->Add( bSizer7, 1, wxEXPAND, 5 );
	
	bSizer->Add( bSizer10, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider2 = new wxSlider( this, wxID_ANY, 20, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer->Add( m_slider2, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton2 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("bitmaps/icons/control.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER );
	bSizer9->Add( m_bpButton2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_bpButton3 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("bitmaps/icons/control-skip-180.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER );
	bSizer9->Add( m_bpButton3, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_bpButton4 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("bitmaps/icons/control-skip.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER );
	bSizer9->Add( m_bpButton4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( -1,20 ), wxLI_VERTICAL );
	bSizer9->Add( m_staticline1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_bpButton5 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("bitmaps/icons/arrow-repeat.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxNO_BORDER );
	bSizer9->Add( m_bpButton5, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("bitmaps/icons/speaker-volume-none.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_bitmap1, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_volumeSlider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	bSizer9->Add( m_volumeSlider, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("bitmaps/icons/speaker-volume.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_bitmap2, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	bSizer->Add( bSizer9, 0, wxEXPAND, 5 );
	
	
	bSizer->Add( 0, 10, 0, 0, 5 );
	
	m_searchSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_query = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_searchSizer->Add( m_query, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_searchGauge = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 70,25 ), wxGA_HORIZONTAL|wxGA_SMOOTH );
	m_searchGauge->Hide();
	
	m_searchSizer->Add( m_searchGauge, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_tracksCount = new wxStaticText( this, wxID_ANY, wxT("0 / 0"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_tracksCount->Wrap( -1 );
	m_tracksCount->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Sans") ) );
	m_tracksCount->Hide();
	
	m_searchSizer->Add( m_tracksCount, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	bSizer->Add( m_searchSizer, 0, wxEXPAND, 5 );
	
	m_trackList = new shr::gui::TrackListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_HEADER|wxLC_NO_SORT_HEADER|wxLC_REPORT|wxSUNKEN_BORDER|wxVSCROLL );
	bSizer->Add( m_trackList, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	this->SetSizer( bSizer );
	this->Layout();
	
	// Connect Events
	m_query->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MainWindowBase::OnQueryUnfocus ), NULL, this );
	m_query->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( MainWindowBase::OnQueryFocus ), NULL, this );
	m_query->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainWindowBase::OnQueryEnter ), NULL, this );
}

MainWindowBase::~MainWindowBase()
{
	// Disconnect Events
	m_query->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MainWindowBase::OnQueryUnfocus ), NULL, this );
	m_query->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( MainWindowBase::OnQueryFocus ), NULL, this );
	m_query->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainWindowBase::OnQueryEnter ), NULL, this );
}

AboutDialogBase::AboutDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_html = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_NO_SELECTION|wxHW_SCROLLBAR_AUTO );
	m_html->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWFRAME ) );
	
	bSizer7->Add( m_html, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1->Realize();
	bSizer7->Add( m_sdbSizer1, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
}

AboutDialogBase::~AboutDialogBase()
{
}
