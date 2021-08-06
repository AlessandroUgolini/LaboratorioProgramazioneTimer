//
// Created by alessandro on 30/07/21.
//

#include "cMain.h"
#include "clockFrame.h"
#include "timerFrame.h"
#include "stopwatchFrame.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(1, cMain::TimerButtonClicked)
    EVT_BUTTON(2, cMain::StopwatchButtonClicked)
    EVT_BUTTON(3, cMain::ClockButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Time Management Application",wxPoint(30, 30),wxSize(800,450)){
    m_btn1= new wxButton(this, 1, "Timer", wxPoint(350,50),wxSize(200,30));
    m_btn2= new wxButton(this, 2, "Stopwatch",wxPoint(350,100),wxSize(200,30));
    m_btn3= new wxButton(this, 3, "Wall digital clock",wxPoint(350,150),wxSize(200,30));
}

cMain::~cMain() {

}

void cMain::TimerButtonClicked(wxCommandEvent &evt) {
    timerFrame *tFrame= new timerFrame(this, wxID_ANY,"Timer",wxPoint(100,100),wxSize(50,50));
    tFrame->Show();
    evt.Skip();
}

void cMain::StopwatchButtonClicked(wxCommandEvent &evt){
    stopwatchFrame *sFrame= new stopwatchFrame(this, wxID_ANY,"Stopwatch",wxPoint(100,100),wxSize(50,50));
    sFrame->Show();
    evt.Skip();
}

void cMain::ClockButtonClicked(wxCommandEvent &evt) {
    clockFrame *cFrame= new clockFrame(this, wxID_ANY,"Clock",wxPoint(100,100),wxSize(50,50));
    cFrame->Show();
    evt.Skip();
}


