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
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/statbmp.h>
#include <wx/gauge.h>
#include <wx/listctrl.h>
#include <wx/frame.h>

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
				wxTextCtrl* m_textCtrl3;
				wxTextCtrl* m_textCtrl4;
				wxStaticText* m_currentPos;
				wxStaticText* m_totalDuration;
				wxSlider* m_slider2;
				wxBitmapButton* m_bpButton2;
				wxBitmapButton* m_bpButton3;
				wxBitmapButton* m_bpButton4;
				wxStaticLine* m_staticline1;
				wxBitmapButton* m_bpButton5;
				
				wxStaticBitmap* m_bitmap1;
				wxSlider* m_volumeSlider;
				wxStaticBitmap* m_bitmap2;
				
				wxBoxSizer* m_searchSizer;
				wxTextCtrl* m_query;
				wxGauge* m_searchGauge;
				shr::gui::TrackList* m_trackList;
				
				// Virtual event handlers, overide them in your derived class
				virtual void OnQueryUnfocus( wxFocusEvent& event ){ event.Skip(); }
				virtual void OnQueryFocus( wxFocusEvent& event ){ event.Skip(); }
				virtual void OnQueryEnter( wxCommandEvent& event ){ event.Skip(); }
				
			
			public:
				MainWindowBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Шарманка"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 604,564 ), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL, const wxString& name = wxT("SharmankaMain") );
				~MainWindowBase();
			
		};
		
	} // namespace gui
} // namespace shr

#endif //___shr_gui__
