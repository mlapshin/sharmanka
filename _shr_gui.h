///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef ___shr_gui__
#define ___shr_gui__

namespace shr{ namespace gui{ class TrackList; } }

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/html/htmlwin.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/listctrl.h>
#include <wx/frame.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

namespace shr
{
	namespace gui
	{
		///////////////////////////////////////////////////////////////////////////////
		/// Class MainWindowBase
		///////////////////////////////////////////////////////////////////////////////
		class MainWindowBase : public wxFrame 
		{
			private:
			
			protected:
				wxToolBar* m_toolBar2;
				wxToolBar* m_toolBar5;
				
				wxHtmlWindow* m_songTitle;
				wxStaticText* m_staticText6;
				wxSlider* m_slider2;
				
				wxTextCtrl* m_query;
				shr::gui::TrackList* m_trackList;
				
				// Virtual event handlers, overide them in your derived class
				virtual void OnQueryUnfocus( wxFocusEvent& event ){ event.Skip(); }
				virtual void OnQueryFocus( wxFocusEvent& event ){ event.Skip(); }
				virtual void OnQueryEnter( wxCommandEvent& event ){ event.Skip(); }
				
			
			public:
				MainWindowBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Шарманка"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 604,564 ), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL, const wxString& name = wxT("SharmankaMain") );
				~MainWindowBase();
			
		};
		
		///////////////////////////////////////////////////////////////////////////////
		/// Class MyPanel1
		///////////////////////////////////////////////////////////////////////////////
		class MyPanel1 : public wxPanel 
		{
			private:
			
			protected:
			
			public:
				MyPanel1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL );
				~MyPanel1();
			
		};
		
	} // namespace gui
} // namespace shr

#endif //___shr_gui__
