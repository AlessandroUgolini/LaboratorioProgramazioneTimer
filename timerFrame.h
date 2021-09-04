//
// Created by alessandro on 02/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_TIMERFRAME_H
#define PROGETTOTIMERLABORATORIO_TIMERFRAME_H

#include <wx/wx.h>
#include "Timer.h"

class timerFrame:public wxFrame {
public:
    timerFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size);

    virtual ~timerFrame();

private:
    wxTextCtrl* boxHour;
    wxButton* hourUp;
    wxButton* hourDown;

    wxTextCtrl* boxMin;
    wxButton* minUp;
    wxButton* minDown;

    wxTextCtrl* boxSec;
    wxButton* secUp;
    wxButton* secDown;

    wxTextCtrl* sep1;
    wxTextCtrl* sep2;

    wxButton* startStopButton;
    wxButton* resetButton;

    Timer* t;

    wxDECLARE_EVENT_TABLE();

    void onHourUpClicked(wxCommandEvent &evt);
    void onHourDownClicked(wxCommandEvent &evt);

    void onMinUpClicked(wxCommandEvent &evt);
    void onMinDownClicked(wxCommandEvent &evt);

    void onSecUpClicked(wxCommandEvent &evt);
    void onSecDownClicked(wxCommandEvent &evt);

    void onStartClicked(wxCommandEvent &evt);
    void onStopClicked(wxCommandEvent &evt);
    void onResetClicked(wxCommandEvent &evt);

    void OnTimer(wxTimerEvent &evt);

    void OnClose(wxCloseEvent& evt);

    void refresh();
    void showButtons();
    void hideButtons();

    void popUp();
};


#endif //PROGETTOTIMERLABORATORIO_TIMERFRAME_H
