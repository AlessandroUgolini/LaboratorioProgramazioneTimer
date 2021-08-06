//
// Created by alessandro on 02/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_CLOCKFRAME_H
#define PROGETTOTIMERLABORATORIO_CLOCKFRAME_H

#include <wx/wx.h>
#include "Clock.h"

class clockFrame :public wxFrame {
public:
    clockFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size);
    virtual ~clockFrame();

private:
    wxTextCtrl* m_timeDisplay24=nullptr;
    wxTextCtrl* m_timeDisplay12=nullptr;
    wxTextCtrl* m_timeDisplayDate=nullptr;
    char* time24h;
    char* time12h;
    char* timeDay;
    Clock* c=nullptr;

    wxDECLARE_EVENT_TABLE();
    void OnClose(wxCloseEvent& evt);
};


#endif //PROGETTOTIMERLABORATORIO_CLOCKFRAME_H
