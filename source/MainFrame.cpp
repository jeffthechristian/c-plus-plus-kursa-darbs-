#include "MainFrame.h"
#include <wx/wx.h>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	//panel configurations
	panel->SetBackgroundColour(wxColour(*wxCYAN));
	
	//binding start buttons to functions
	chatButton->Bind(wxEVT_BUTTON, &MainFrame::ChatClicked, this);
	playButton->Bind(wxEVT_BUTTON, &MainFrame::PlayClicked, this);
	exitButton->Bind(wxEVT_BUTTON, &MainFrame::ExitClicked, this);

	//binding chat buttons to functions
	sendMessageButton->Bind(wxEVT_BUTTON, &MainFrame::SendMessageClicked, this);
	chatGoBackButton->Bind(wxEVT_BUTTON, &MainFrame::ChatGoBackClicked, this);
	inputChatText->Bind(wxEVT_TEXT_ENTER, &MainFrame::SendMessageClicked, this);

	//binding play buttons to functions
	rockButton->Bind(wxEVT_BUTTON, &MainFrame::RockClicked, this);
	scissorsButton->Bind(wxEVT_BUTTON, &MainFrame::ScissorsClicked, this);
	paperButton->Bind(wxEVT_BUTTON, &MainFrame::PaperClicked, this);

	//what should show and what shouldn't at start
	startConditions();

}
//start screen buttons
void MainFrame::ChatClicked(wxCommandEvent& evt) {
	//what should and what shouldn't show when user wants to use chat
	chatConditions();
}

void MainFrame::PlayClicked(wxCommandEvent& evt) {
	//what should and what shouldn't show when user wants to play a game
	playConditions();
}

void MainFrame::ExitClicked(wxCommandEvent& evt) {
	Close(TRUE);

}


//chat screen buttons
void MainFrame::SendMessageClicked(wxCommandEvent& evt) {
	chatWithMonkey();
}

void MainFrame::ChatGoBackClicked(wxCommandEvent& evt) {
	//don't touch Hide(); stuff it no works elsewhere like it should
	startIcon->Hide();
	rockMonkey->Hide();
	scissorsMonkey->Hide();
	paperMonkey->Hide();

	startConditions();
}

//play screen buttons
void MainFrame::RockClicked(wxCommandEvent& evt) {
	gameScreen->AppendText("\n\nPlayer chose: ROCK\n");
	//program chooses random number from 1 to 3
	int random = 1 + (rand() % 3);

	//allocate each number with rock,paper,scissors and see who wins
	if (random == 1) {
		//depending on what monkey chooses change image
		startIcon->Hide();
		rockMonkey->Show();
		scissorsMonkey->Hide();
		paperMonkey->Hide();

		gameScreen->AppendText("Monkey chose: ROCK\n");
		gameScreen->AppendText("DRAW!");
	}
	if (random == 2) {
		startIcon->Hide();
		rockMonkey->Hide();
		scissorsMonkey->Show();
		paperMonkey->Hide();

		gameScreen->AppendText("Monkey chose: SCISSORS\n");
		gameScreen->AppendText("Player wins!");
	}
	if (random == 3) {
		startIcon->Hide();
		rockMonkey->Hide();
		scissorsMonkey->Hide();
		paperMonkey->Show();

		gameScreen->AppendText("Monkey chose: PAPER\n");
		gameScreen->AppendText("Monkey wins!");
	}
}

void MainFrame::ScissorsClicked(wxCommandEvent& evt) {
	gameScreen->AppendText("\n\nPlayer chose: SCISSORS\n");
	//program chooses random number from 1 to 3
	int random = 1 + (rand() % 3);

	//allocate each number with rock,paper,scissors and see who wins
	if (random == 1) {
		//depending on what monkey chooses change image
		startIcon->Hide();
		rockMonkey->Show();
		scissorsMonkey->Hide();
		paperMonkey->Hide();

		gameScreen->AppendText("Monkey chose: ROCK\n");
		gameScreen->AppendText("Monkey wins!");
	}
	if (random == 2) {
		startIcon->Hide();
		rockMonkey->Hide();
		scissorsMonkey->Show();
		paperMonkey->Hide();

		gameScreen->AppendText("Monkey chose: SCISSORS\n");
		gameScreen->AppendText("DRAW!");
	}
	if (random == 3) {
		startIcon->Hide();
		rockMonkey->Hide();
		scissorsMonkey->Hide();
		paperMonkey->Show();

		gameScreen->AppendText("Monkey chose: PAPER\n");
		gameScreen->AppendText("Player wins!");
	}
}

void MainFrame::PaperClicked(wxCommandEvent& evt) {
	gameScreen->AppendText("\n\nPlayer chose: PAPER\n");
	//program chooses random number from 1 to 3
	int random = 1 + (rand() % 3);

	//allocate each number with rock,paper,scissors and see who wins
	if (random == 1) {
		//depending on what monkey chooses change image
		startIcon->Hide();
		rockMonkey->Show();
		scissorsMonkey->Hide();
		paperMonkey->Hide();

		gameScreen->AppendText("Monkey chose: ROCK\n");
		gameScreen->AppendText("Player wins!");
	}
	if (random == 2) {
		startIcon->Hide();
		rockMonkey->Hide();
		scissorsMonkey->Show();
		paperMonkey->Hide();

		gameScreen->AppendText("Monkey chose: SCISSORS\n");
		gameScreen->AppendText("Monkey wins!");
	}
	if (random == 3) {
		startIcon->Hide();
		rockMonkey->Hide();
		scissorsMonkey->Hide();
		paperMonkey->Show();

		gameScreen->AppendText("Monkey chose: PAPER\n");
		gameScreen->AppendText("DRAW!");
	}
}

//chat
void MainFrame::chatWithMonkey() {
	sentMessages->SetFont(GetFont().Scale(1.2));
	sentMessages->HideNativeCaret();
	inputChatText->SetFocus();
	//read file 
	ifstream readQuestions("source/resources/texts/questions.txt");
	std::string line;
	//user input change to string
	std::string s = inputChatText->GetValue().ToStdString();
	//if user input is empty send message and monkey replies
	if (s == "") {
		sentMessages->AppendText("You: " + s + "\n");
		sentMessages->AppendText("Monkey: Did you say something?\n");
	}
	//if it is not empty then send message and clean message input thing 
	else {
		sentMessages->AppendText("You: " + s + "\n");
		inputChatText->Clear();
		//each line is split into 2, first half question, other answer
		while (std::getline(readQuestions, line)) {
			auto sep_index = line.find(';');
			std::string question = line.substr(0, sep_index);
			std::string answer = line.substr(sep_index +1);
			//if question from file is the same as user input then monkey says the answer of that question.. yes
			if (s == question) {
				sentMessages->AppendText("Monkey: " + answer + "\n");
				return;
			}
		}
		//if none of the conditions are met what user input then monkey no understando
		sentMessages->AppendText("Monkey: I don't understand :(\n");
	}

	readQuestions.close();
}

void MainFrame::startConditions() {
	//functions to call (don't put them elsewhere or no work)
	startImages();

	//buttons
	chatButton->Show();
	playButton->Show();
	exitButton->Show();

	rockButton->Hide();
	scissorsButton->Hide();
	paperButton->Hide();

	sendMessageButton->Hide();
	chatGoBackButton->Hide();

	//images
	chatIcon->Hide();

	rockMonkey->Hide();
	scissorsMonkey->Hide();
	paperMonkey->Hide();

	//etc
	startText->Show();
	startText->SetFont(GetFont().Scale(2));
	sentMessages->Hide();
	inputChatText->Hide();
	gameScreen->Hide();
}

void MainFrame::chatConditions() {
	//buttons
	chatButton->Hide();
	playButton->Hide();
	exitButton->Hide();

	sendMessageButton->Show();
	chatGoBackButton->Show();

	//images
	startIcon->Hide();
	chatIcon->Show();

	rockMonkey->Hide();
	scissorsMonkey->Hide();
	paperMonkey->Hide();

	//etc
	startText->Hide();
	inputChatText->Show();
	sentMessages->Show();
}

void MainFrame::playConditions() {
	//buttons
	chatButton->Hide();
	playButton->Hide();
	exitButton->Hide();

	rockButton->Show();
	scissorsButton->Show();
	paperButton->Show();

	chatGoBackButton->Show();

	//etc
	startText->Hide();
	gameScreen->AppendText("ROCK, PAPER, SCISSORS!");
	gameScreen->Show();
	gameScreen->SetFont(GetFont().Scale(1.2));
	gameScreen->HideNativeCaret();
}

void MainFrame::startImages() {
	//start images
	wxPNGHandler* imageHandler = new wxPNGHandler;
	wxImage::AddHandler(imageHandler);

	startIcon = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("source/resources/images/bigGorilla.png", wxBITMAP_TYPE_PNG), wxPoint(240, 10), wxSize(270, 270));
	chatIcon = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("source/resources/images/medGorilla.png", wxBITMAP_TYPE_PNG), wxPoint(350, 10), wxSize(128, 128));

	rockMonkey = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("source/resources/images/rockGorilla.png", wxBITMAP_TYPE_PNG), wxPoint(240, 10), wxSize(270, 270));
	scissorsMonkey = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("source/resources/images/scissorsGorilla.png", wxBITMAP_TYPE_PNG), wxPoint(240, 10), wxSize(270, 270));
	paperMonkey = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("source/resources/images/paperGorilla.png", wxBITMAP_TYPE_PNG), wxPoint(240, 10), wxSize(270, 270));

}