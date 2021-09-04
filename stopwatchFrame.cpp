//
// Created by alessandro on 02/08/21.
//

#include "stopwatchFrame.h"

wxBEGIN_EVENT_TABLE(stopwatchFrame,wxFrame)
                EVT_CLOSE(stopwatchFrame::OnClose)

                EVT_TIMER(-2,stopwatchFrame::OnStopwatch)

                EVT_BUTTON(21,stopwatchFrame::onStartClicked)
                EVT_BUTTON(22,stopwatchFrame::onStopClicked)
                EVT_BUTTON(23,stopwatchFrame::onResetClicked)

wxEND_EVENT_TABLE()

stopwatchFrame::stopwatchFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                       const wxSize &size) : wxFrame(parent, id, title, pos, size) {
    SetBackgroundColour(*wxBLACK);
    boxHour=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(10,60),wxSize(50,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    boxMin=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(80,60),wxSize(50,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    boxSec=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(150,60),wxSize(50,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    sep1=new wxTextCtrl(this,wxID_ANY,":",wxPoint(60,60),wxSize(20,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);
    sep2=new wxTextCtrl(this,wxID_ANY,":",wxPoint(130,60),wxSize(20,20),wxBORDER_NONE|wxTE_READONLY|wxTE_CENTRE);

    startStopButton=new wxButton(this, 21, "Start",wxPoint(30,115),wxSize(60,30));
    resetButton=new wxButton(this, 23, "Reset",wxPoint(120,115),wxSize(60,30));
    s= new Stopwatch(this,-2);
}

stopwatchFrame::~stopwatchFrame(){
    s->~Stopwatch();
}

void stopwatchFrame::onStartClicked(wxCommandEvent &evt) {
    s->start();
    startStopButton = new wxButton(this, 22, "Stop", wxPoint(30, 115), wxSize(60, 30));
}

void stopwatchFrame::onStopClicked(wxCommandEvent &evt){
    s->stop();
    stopwatchFrame::refresh();
    startStopButton=new wxButton(this, 21, "Start",wxPoint(30,115),wxSize(60,30));
}

void stopwatchFrame::onResetClicked(wxCommandEvent &evt){
    s->reset();
    stopwatchFrame::refresh();
    startStopButton=new wxButton(this, 21, "Start",wxPoint(30,115),wxSize(60,30));
}

void stopwatchFrame::OnClose(wxCloseEvent &evt) {
    s->stop();
    Destroy();
}

void stopwatchFrame::OnStopwatch(wxTimerEvent &evt){
    s->setSec(s->getSec()+1);
    stopwatchFrame::refresh();
}

void stopwatchFrame::refresh(){
    boxHour->Replace(0,80,s->extendTime(s->getHour()));
    boxMin->Replace(0,80,s->extendTime(s->getMin()));
    boxSec->Replace(0,80,s->extendTime(s->getSec()));
}
