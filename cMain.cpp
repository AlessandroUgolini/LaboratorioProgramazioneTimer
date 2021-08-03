//
// Created by alessandro on 30/07/21.
//

#include "cMain.h"
#include "clockFrame.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(1, cMain::TimerButtonClicked)
    EVT_BUTTON(2, cMain::StopwatchButtonClicked)
    EVT_BUTTON(3, cMain::WDClockButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Time Management Application",wxPoint(30, 30),wxSize(800,450)){
    m_btn1= new wxButton(this, 1, "Timer", wxPoint(350,50),wxSize(200,30));
    m_btn2= new wxButton(this, 2, "Stopwatch",wxPoint(350,100),wxSize(200,30));
    m_btn3= new wxButton(this, 3, "Wall digital clock",wxPoint(350,150),wxSize(200,30));
}

cMain::~cMain() {

}

void cMain::TimerButtonClicked(wxCommandEvent &evt) {
    clockFrame *Frame= new clockFrame12(this, wxID_ANY,"Wall Digital Clock",wxPoint(100,100),wxSize(50,50));
    Frame->Show();
}

void cMain::StopwatchButtonClicked(wxCommandEvent &evt){

}


