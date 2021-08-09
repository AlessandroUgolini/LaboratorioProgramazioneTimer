//
// Created by alessandro on 02/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_TIMERFRAME_H
#define PROGETTOTIMERLABORATORIO_TIMERFRAME_H

#include <wx/wx.h>
#include "Timer.h"

//TODO aggiungere che le caselle sono solo in lettura
//TODO aggiungere un piccolo modo per mostrare che il timer scorre
//TODO lavorare sulla grafica del timer

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

    wxButton* startButton;
    wxButton* stopButton;
    wxButton* resetButton;

    wxTextCtrl* sep1;
    wxTextCtrl* sep2;

    char* bh;
    char* bm;
    char* bs;

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

    void OnClose(wxCloseEvent& evt);


};


#endif //PROGETTOTIMERLABORATORIO_TIMERFRAME_H
