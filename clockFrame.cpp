//
// Created by alessandro on 02/08/21.
//

#include "clockFrame.h"

wxBEGIN_EVENT_TABLE(clockFrame,wxFrame)
            EVT_CLOSE(clockFrame::OnClose)
            EVT_TIMER(-1,clockFrame::OnClock)
wxEND_EVENT_TABLE()

clockFrame::clockFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,const wxSize &size) : wxFrame(parent, id, title, pos, size) {
    SetBackgroundColour(*wxBLACK);
    m_timeDisplayDate= new wxTextCtrl(this,wxID_ANY,"", wxPoint(50,20),wxSize(100,25),wxBORDER_NONE|wxTE_READONLY);
    m_timeDisplay24= new wxTextCtrl(this, wxID_ANY,"", wxPoint(50,70), wxSize(100,25),wxBORDER_NONE|wxTE_READONLY);
    m_timeDisplay12= new wxTextCtrl(this, wxID_ANY,"", wxPoint(50,120), wxSize(100,25),wxBORDER_NONE|wxTE_READONLY);
    c= new Clock(this,-1);
}

clockFrame::~clockFrame() {
    c->~Clock();
}

void clockFrame::OnClose(wxCloseEvent& evt){
    Destroy();
    evt.Skip();
}

void clockFrame::OnClock(wxTimerEvent &evt){
    std::string tb24=c->getTime24();
    std::string tb12=c->getTime12();
    std::string tbday=c->getTimeDay();
    m_timeDisplay24->Replace(0,80,tb24);
    m_timeDisplay12->Replace(0,80,tb12);
    m_timeDisplayDate->Replace(0,80,tbday);
    evt.Skip();
}

Clock *clockFrame::getC() const {
    return c;
}
