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

    virtual ~stopwatchFrame();

private:
    wxTextCtrl* boxHour;
    wxTextCtrl* boxMin;
    wxTextCtrl* boxSec;

    wxButton* startStopButton;
    wxButton* resetButton;

    wxTextCtrl* sep1;
    wxTextCtrl* sep2;

    char* bh;
    char* bm;
    char* bs;

    Stopwatch* s;

wxDECLARE_EVENT_TABLE();

    void onStartClicked(wxCommandEvent &evt);
    void onStopClicked(wxCommandEvent &evt);
    void onResetClicked(wxCommandEvent &evt);

    void OnClose(wxCloseEvent& evt);

};


#endif //PROGETTOTIMERLABORATORIO_STOPWATCHFRAME_H
