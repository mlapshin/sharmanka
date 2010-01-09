///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "shr/gui/TrackList.hpp"

#include "_shr_gui.h"

///////////////////////////////////////////////////////////////////////////
using namespace shr::gui;

MainWindowBase::MainWindowBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxSize( 200,300 ), wxDefaultSize );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_toolBar2 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("bitmaps/icons/control.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString );
	m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("bitmaps/icons/control-skip-180.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("bitmaps/icons/control-skip.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar2->AddSeparator();
	m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("bitmaps/icons/arrow-repeat.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString );
	m_toolBar2->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("bitmaps/icons/arrow-switch.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString );
	m_toolBar2->Realize();
	
	bSizer9->Add( m_toolBar2, 1, wxEXPAND, 5 );
	
	m_toolBar5 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	m_toolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("bitmaps/icons/gear.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar5->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("bitmaps/icons/speaker-volume.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar5->Realize();
	
	bSizer9->Add( m_toolBar5, 0, wxEXPAND, 5 );
	
	bSizer8->Add( bSizer9, 0, wxEXPAND, 5 );
	
	
	bSizer8->Add( 0, 5, 0, 0, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_songTitle = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_NEVER|wxNO_BORDER );
	bSizer10->Add( m_songTitle, 1, 0, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("3:05"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer10->Add( m_staticText6, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer8->Add( bSizer10, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_slider2 = new wxSlider( this, wxID_ANY, 20, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer8->Add( m_slider2, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer8->Add( 0, 10, 0, 0, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_textCtrl1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_bpButton6 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("../fugue/icons/magnifier.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer11->Add( m_bpButton6, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer8->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_songs = new TrackList( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_NO_SORT_HEADER|wxLC_REPORT|wxSUNKEN_BORDER|wxVSCROLL );
	bSizer8->Add( m_songs, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	this->SetSizer( bSizer8 );
	this->Layout();
}

MainWindowBase::~MainWindowBase()
{
}
