#include "Monkey.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(Monkey);

bool Monkey::OnInit() {
	//create frame
	MainFrame* mainFrame = new MainFrame("ME & MYSELF AND MONKEY");
	mainFrame->SetClientSize(500, 400);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}