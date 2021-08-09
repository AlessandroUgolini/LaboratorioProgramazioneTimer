//
// Created by alessandro on 02/08/21.
//

#include "stopwatchFrame.h"

wxBEGIN_EVENT_TABLE(stopwatchFrame,wxFrame)
                EVT_CLOSE(stopwatchFrame::OnClose)

                EVT_BUTTON(1,stopwatchFrame::onStartClicked)
                EVT_BUTTON(2,stopwatchFrame::onStopClicked)
                EVT_BUTTON(3,stopwatchFrame::onResetClicked)

wxEND_EVENT_TABLE()

stopwatchFrame::stopwatchFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                       const wxSize &size) : wxFrame(parent, id, title, pos, size) {
    boxHour=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(10,30),wxSize(40,20));
    boxMin=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(70,30),wxSize(40,20));
    boxSec=new wxTextCtrl(this,wxID_ANY,"00",wxPoint(120,30),wxSize(40,20));
    sep1=new wxTextCtrl(this,wxID_ANY,":",wxPoint(50,30),wxSize(20,20));
    sep2=new wxTextCtrl(this,wxID_ANY,":",wxPoint(100,30),wxSize(20,20));

    startButton=new wxButton(this, 1, "Start",wxPoint(10,85),wxSize(60,30));
    stopButton=new wxButton(this, 2, "Stop",wxPoint(80,85),wxSize(60,30));
    resetButton=new wxButton(this, 3, "Reset",wxPoint(150,85),wxSize(60,30));
    s= new Stopwatch(boxHour,boxMin,boxSec);
}

stopwatchFrame::~stopwatchFrame(){

}

void stopwatchFrame::onStartClicked(wxCommandEvent &evt){
    s->start();
}

void stopwatchFrame::onStopClicked(wxCommandEvent &evt){
    s->stop();
}

void stopwatchFrame::onResetClicked(wxCommandEvent &evt){
    s->reset();
}

void stopwatchFrame::OnClose(wxCloseEvent &evt) {
    Destroy();
}