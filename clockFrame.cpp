//
// Created by alessandro on 02/08/21.
//

#include "clockFrame.h"

wxBEGIN_EVENT_TABLE(clockFrame,wxFrame)
            EVT_CLOSE(clockFrame::OnClose)
wxEND_EVENT_TABLE()

clockFrame::clockFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,const wxSize &size) : wxFrame(parent, id, title, pos, size) {
    m_timeDisplay24= new wxTextCtrl(this, wxID_ANY, time24h, wxPoint(0,50), wxDefaultSize);
    m_timeDisplay12= new wxTextCtrl(this, wxID_ANY, time12h, wxPoint(0,100), wxDefaultSize);
    m_timeDisplayDate= new wxTextCtrl(this,wxID_ANY,timeDay,wxPoint(0,0),wxDefaultSize);
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
    c->~Clock();
    Destroy();
}
