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

    Clock *getC() const;

private:
    wxTextCtrl* m_timeDisplay24;
    wxTextCtrl* m_timeDisplay12;
    wxTextCtrl* m_timeDisplayDate;

    Clock* c;

    wxDECLARE_EVENT_TABLE();
    void OnClose(wxCloseEvent& evt);
    void OnClock(wxTimerEvent &evt);
};


#endif //PROGETTOTIMERLABORATORIO_CLOCKFRAME_H
