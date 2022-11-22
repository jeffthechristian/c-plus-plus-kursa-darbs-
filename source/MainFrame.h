#pragma once
#include <wx/wx.h>
using namespace std;

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);


private:
	//panel
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 400));
	//start 
	//start buttons
	wxButton* chatButton = new wxButton(panel, wxID_ANY, "CHAT WITH ME", wxPoint(40, 325), wxSize(110, 40));
	void ChatClicked(wxCommandEvent& evt);
	wxButton* playButton = new wxButton(panel, wxID_ANY, "PLAY WITH ME", wxPoint(190, 325), wxSize(110, 40));
	void PlayClicked(wxCommandEvent& evt);
	wxButton* exitButton = new wxButton(panel, wxID_ANY, "EXIT", wxPoint(340, 325), wxSize(110, 40));
	void ExitClicked(wxCommandEvent& evt);

	//start images
	void startImages();
	wxStaticBitmap* startIcon;

	//start text stuff
	wxStaticText* startText = new wxStaticText(panel, wxID_ANY, "Welcome, friend!", wxPoint(20, 20), wxSize(300, 25));



	//chat
	//chat text stuff
	wxTextCtrl* inputChatText = new wxTextCtrl(panel, wxID_ANY, "Enter Text", wxPoint(20, 350), wxSize(300, 25), wxTE_PROCESS_ENTER);
	wxTextCtrl* sentMessages = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 50), wxSize(300, 275), wxTE_MULTILINE | wxTE_READONLY);

	//chat buttons
	wxButton* sendMessageButton = new wxButton(panel, wxID_ANY, "SEND", wxPoint(330, 350), wxSize(50, 25));
	void SendMessageClicked(wxCommandEvent& evt);
	wxButton* chatGoBackButton = new wxButton(panel, wxID_ANY, "GO BACK", wxPoint(10, 10), wxSize(75, 30));
	void ChatGoBackClicked(wxCommandEvent& evt);	

	//chat images
	wxStaticBitmap* chatIcon;

	//play
	//play buttons
	wxButton* rockButton = new wxButton(panel, wxID_ANY, "ROCK", wxPoint(40, 325), wxSize(110, 40));
	void RockClicked(wxCommandEvent& evt);
	wxButton* scissorsButton = new wxButton(panel, wxID_ANY, "SCISSORS", wxPoint(190, 325), wxSize(110, 40));
	void ScissorsClicked(wxCommandEvent& evt);
	wxButton* paperButton = new wxButton(panel, wxID_ANY, "PAPER", wxPoint(340, 325), wxSize(110, 40));
	void PaperClicked(wxCommandEvent& evt);

	//play text stuff
	wxTextCtrl* gameScreen = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 50), wxSize(200, 250), wxTE_MULTILINE | wxTE_READONLY);

	//play images
	wxStaticBitmap* rockMonkey;
	wxStaticBitmap* scissorsMonkey;
	wxStaticBitmap* paperMonkey;

	//functions
	void startConditions();
	void chatConditions();
	void playConditions();
	void chatWithMonkey();
};


