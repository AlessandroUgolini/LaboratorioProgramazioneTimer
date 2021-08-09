//
// Created by alessandro on 02/08/21.
//

#include "timerFrame.h"

wxBEGIN_EVENT_TABLE(timerFrame,wxFrame)
                EVT_CLOSE(timerFrame::OnClose)

                EVT_BUTTON(1, timerFrame::onHourUpClicked)
                EVT_BUTTON(2, timerFrame::onHourDownClicked)
                EVT_BUTTON(3, timerFrame::onMinUpClicked)
                EVT_BUTTON(4, timerFrame::onMinDownClicked)
                EVT_BUTTON(5, timerFrame::onSecUpClicked)
                EVT_BUTTON(6, timerFrame::onSecDownClicked)
                EVT_BUTTON(7,timerFrame::onStartClicked)
                EVT_BUTTON(8,timerFrame::onStopClicked)
                EVT_BUTTON(9,timerFrame::onResetClicked)

wxEND_EVENT_TABLE()

timerFrame::timerFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                       const wxSize &size) : wxFrame(parent, id, title, pos, size) {
    boxHour=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(10,30),wxSize(40,20));
    boxMin=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(70,30),wxSize(40,20));
    boxSec=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(120,30),wxSize(40,20));
    sep1=new wxTextCtrl(this,wxID_ANY,":",wxPoint(50,30),wxSize(20,20));
    sep2=new wxTextCtrl(this,wxID_ANY,":",wxPoint(100,30),wxSize(20,20));

    hourUp=new wxButton(this, 1, "^", wxPoint(10,5),wxSize(40,20));
    hourDown=new wxButton(this, 2, "v", wxPoint(10,55),wxSize(40,20));
    minUp=new wxButton(this, 3, "^", wxPoint(70,5),wxSize(40,20));
    minDown=new wxButton(this, 4, "V", wxPoint(70,55),wxSize(40,20));
    secUp=new wxButton(this, 5, "^", wxPoint(120,5),wxSize(40,20));
    secDown=new wxButton(this, 6, "V", wxPoint(120,55),wxSize(40,20));

    startButton=new wxButton(this, 7, "Start",wxPoint(10,85),wxSize(60,30));
    stopButton=new wxButton(this, 8, "Stop",wxPoint(80,85),wxSize(60,30));
    resetButton=new wxButton(this, 9, "Reset",wxPoint(150,85),wxSize(60,30));
    t= new Timer(boxHour,boxMin,boxSec);
}

timerFrame::~timerFrame() {}

void timerFrame::onHourUpClicked(wxCommandEvent &evt) {
    if(! t->isRunning())
        t->setHour(t->getHour()+1);
}

void timerFrame::onHourDownClicked(wxCommandEvent &evt) {
    if(! t->isRunning())
        t->setHour(t->getHour()-1);
}

void timerFrame::onMinUpClicked(wxCommandEvent &evt) {
    if(! t->isRunning())
        t->setMin(t->getMin()+1);
}

void timerFrame::onMinDownClicked(wxCommandEvent &evt) {
    if(! t->isRunning())
        t->setMin(t->getMin()-1);
}

void timerFrame::onSecUpClicked(wxCommandEvent &evt) {
    if(! t->isRunning())
        t->setSec(t->getSec()+1);
}

void timerFrame::onSecDownClicked(wxCommandEvent &evt) {
    if(! t->isRunning())
        t->setSec(t->getSec()-1);
}

void timerFrame::onStartClicked(wxCommandEvent &evt){
    t->start();
}

void timerFrame::onStopClicked(wxCommandEvent &evt){
    t->stop();
}

void timerFrame::onResetClicked(wxCommandEvent &evt){
    t->reset();
}

void timerFrame::OnClose(wxCloseEvent &evt) {
    t->~Timer();
    Destroy();
}
