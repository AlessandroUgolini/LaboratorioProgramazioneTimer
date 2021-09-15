//
// Created by alessandro on 02/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_STOPWATCHFRAME_H
#define PROGETTOTIMERLABORATORIO_STOPWATCHFRAME_H

#include <wx/wx.h>
#include "Stopwatch.h"

class stopwatchFrame :public wxFrame{
public:
    stopwatchFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size);

    Stopwatch* getS() const;

    virtual ~stopwatchFrame();

private:
    void refresh();

    wxTextCtrl* boxHour;
    wxTextCtrl* boxMin;
    wxTextCtrl* boxSec;

    wxTextCtrl* sep1;
    wxTextCtrl* sep2;

    wxButton* startStopButton;
    wxButton* resetButton;

    Stopwatch* s;

wxDECLARE_EVENT_TABLE();

    void onStartClicked(wxCommandEvent &evt);
    void onStopClicked(wxCommandEvent &evt);
    void onResetClicked(wxCommandEvent &evt);

    void OnClose(wxCloseEvent& evt);

    void OnStopwatch(wxTimerEvent &evt);

};


#endif //PROGETTOTIMERLABORATORIO_STOPWATCHFRAME_H
