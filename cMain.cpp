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

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Time Management Application",wxPoint(30, 30),wxSize(450,250)){
    SetBackgroundColour(*wxBLACK);
    m_btn1= new wxButton(this, 1, "Timer", wxPoint(125,50),wxSize(200,30));
    m_btn2= new wxButton(this, 2, "Stopwatch",wxPoint(125,100),wxSize(200,30));
    m_btn3= new wxButton(this, 3, "Wall digital clock",wxPoint(125,150),wxSize(200,30));
}

cMain::~cMain() {

}

void cMain::TimerButtonClicked(wxCommandEvent &evt) {
    timerFrame *tFrame= new timerFrame(this, 10,"Timer",wxPoint(100,100),wxSize(210,200));
    tFrame->Show();
    evt.Skip();
}

void cMain::StopwatchButtonClicked(wxCommandEvent &evt){
    stopwatchFrame *sFrame= new stopwatchFrame(this, wxID_ANY,"Stopwatch",wxPoint(100,100),wxSize(210,200));
    sFrame->Show();
    evt.Skip();
}

void cMain::ClockButtonClicked(wxCommandEvent &evt) {
    clockFrame *cFrame= new clockFrame(this, wxID_ANY,"Clock",wxPoint(100,100),wxSize(200,200));
    cFrame->Show();
    evt.Skip();
}


