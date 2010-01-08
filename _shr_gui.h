///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef ___shr_gui__
#define ___shr_gui__

#include <wx/srchctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
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
				wxSearchCtrl* m_searchBox;
				wxListCtrl* m_listCtrl1;
				wxStatusBar* m_statusBar;
			
			public:
				MainWindowBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Шарманка"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 498,509 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, const wxString& name = wxT("SharmankaMain") );
				~MainWindowBase();
			
		};
		
	} // namespace gui
} // namespace shr

#endif //___shr_gui__
