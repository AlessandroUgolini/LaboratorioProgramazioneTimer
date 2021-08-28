//
// Created by alessandro on 02/08/21.
//

#include "clockFrame.h"

wxBEGIN_EVENT_TABLE(clockFrame,wxFrame)
            EVT_CLOSE(clockFrame::OnClose)
wxEND_EVENT_TABLE()

clockFrame::clockFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,const wxSize &size) : wxFrame(parent, id, title, pos, size) {
    SetBackgroundColour(*wxBLACK);
    m_timeDisplayDate= new wxTextCtrl(this,wxID_ANY,timeDay,wxPoint(50,20),wxSize(100,25),wxBORDER_NONE|wxTE_READONLY);
    m_timeDisplay24= new wxTextCtrl(this, wxID_ANY, time24h, wxPoint(50,70), wxSize(100,25),wxBORDER_NONE|wxTE_READONLY);
    m_timeDisplay12= new wxTextCtrl(this, wxID_ANY, time12h, wxPoint(50,120), wxSize(100,25),wxBORDER_NONE|wxTE_READONLY);
    c= new Clock(m_timeDisplay24,m_timeDisplay12,m_timeDisplayDate);
    time24h=c->getTb24();
    time12h=c->getTb12();
    timeDay=c->getTbday();
    c->Start(1000,false);
}

clockFrame::~clockFrame() {
    delete[] time24h;
    delete[] time12h;
    delete[] timeDay;
}

void clockFrame::OnClose(wxCloseEvent& evt){
    c->Stop();
    Destroy();
}
