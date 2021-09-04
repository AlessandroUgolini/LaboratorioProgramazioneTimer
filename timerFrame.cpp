//
// Created by alessandro on 02/08/21.
//

#include "timerFrame.h"

wxBEGIN_EVENT_TABLE(timerFrame,wxFrame)
                EVT_CLOSE(timerFrame::OnClose)

                EVT_BUTTON(11, timerFrame::onHourUpClicked)
                EVT_BUTTON(12, timerFrame::onHourDownClicked)
                EVT_BUTTON(13, timerFrame::onMinUpClicked)
                EVT_BUTTON(14, timerFrame::onMinDownClicked)
                EVT_BUTTON(15, timerFrame::onSecUpClicked)
                EVT_BUTTON(16, timerFrame::onSecDownClicked)
                EVT_BUTTON(17,timerFrame::onStartClicked)
                EVT_BUTTON(18,timerFrame::onStopClicked)
                EVT_BUTTON(19,timerFrame::onResetClicked)

                EVT_TIMER(10,timerFrame::OnTimer)

wxEND_EVENT_TABLE()

timerFrame::timerFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                       const wxSize &size) : wxFrame(parent, id, title, pos, size) {
    SetBackgroundColour(*wxBLACK);
    boxHour=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(10,60),wxSize(50,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    boxMin=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(80,60),wxSize(50,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    boxSec=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(150,60),wxSize(50,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    sep1=new wxTextCtrl(this,wxID_ANY,":",wxPoint(60,60),wxSize(20,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    sep2=new wxTextCtrl(this,wxID_ANY,":",wxPoint(130,60),wxSize(20,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);

    hourUp=new wxButton(this, 11, "+", wxPoint(15,35),wxSize(40,20));
    hourDown=new wxButton(this, 12, "-", wxPoint(15,85),wxSize(40,20));
    minUp=new wxButton(this, 13, "+", wxPoint(85,35),wxSize(40,20));
    minDown=new wxButton(this, 14, "-", wxPoint(85,85),wxSize(40,20));
    secUp=new wxButton(this, 15, "+", wxPoint(155,35),wxSize(40,20));
    secDown=new wxButton(this, 16, "-", wxPoint(155,85),wxSize(40,20));

    startStopButton=new wxButton(this, 17, "Start",wxPoint(30,115),wxSize(60,30));
    resetButton=new wxButton(this, 19, "Reset",wxPoint(120,115),wxSize(60,30));
    t= new Timer(this,10);

}

timerFrame::~timerFrame() {}

void timerFrame::onHourUpClicked(wxCommandEvent &evt) {
    if(! t->isRunning()) {
        t->setHour(t->getHour() + 1);
        refresh();
    }
}

void timerFrame::onHourDownClicked(wxCommandEvent &evt) {
    if(! t->isRunning()) {
        t->setHour(t->getHour() - 1);
        refresh();
    }
}

void timerFrame::onMinUpClicked(wxCommandEvent &evt) {
    if(! t->isRunning()) {
        t->setMin(t->getMin() + 1);
        refresh();
    }
}

void timerFrame::onMinDownClicked(wxCommandEvent &evt) {
    if(! t->isRunning()) {
        t->setMin(t->getMin() - 1);
        refresh();
    }
}

void timerFrame::onSecUpClicked(wxCommandEvent &evt) {
    if(! t->isRunning()) {
        t->setSec(t->getSec() + 1);
        refresh();
    }
}

void timerFrame::onSecDownClicked(wxCommandEvent &evt) {
    if(! t->isRunning()) {
        t->setSec(t->getSec() - 1);
        refresh();
    }
}

void timerFrame::onStartClicked(wxCommandEvent &evt){
    if(t->isZero()==false) {
        t->start();
        timerFrame::hideButtons();
    }
}

void timerFrame::onStopClicked(wxCommandEvent &evt){
    t->stop();
    timerFrame::refresh();
    timerFrame::showButtons();
}

void timerFrame::onResetClicked(wxCommandEvent &evt){
    t->reset();
    timerFrame::refresh();
    timerFrame::showButtons();
}

void timerFrame::OnTimer(wxTimerEvent &evt){
    t->setSec((t->getSec())-1);
    t->update();
    refresh();
    if(t->isZero()){
        t->stop();
        timerFrame::popUp();
        timerFrame::showButtons();
    }
}

void timerFrame::OnClose(wxCloseEvent &evt) {
    t->stop();
    t->~Timer();
    Destroy();
}

void timerFrame::refresh(){
    boxHour->Replace(0,80,t->extendTime(t->getHour()));
    boxMin->Replace(0,80,t->extendTime(t->getMin()));
    boxSec->Replace(0,80,t->extendTime(t->getSec()));
}

void timerFrame::showButtons(){
    hourUp->Show();
    hourDown->Show();
    minUp->Show();
    minDown->Show();
    secUp->Show();
    secDown->Show();
    startStopButton=new wxButton(this, 17, "Start",wxPoint(30,115),wxSize(60,30));
}

void timerFrame::hideButtons(){
    hourUp->Hide();
    hourDown->Hide();
    minUp->Hide();
    minDown->Hide();
    secUp->Hide();
    secDown->Hide();
    startStopButton=new wxButton(this, 18, "Stop",wxPoint(30,115),wxSize(60,30));
}


void timerFrame::popUp(){
    wxMessageBox(wxT("TIME HAS RUN OUT"), wxT("Timer"),wxICON_INFORMATION);
}