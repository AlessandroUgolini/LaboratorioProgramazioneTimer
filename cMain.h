//
// Created by alessandro on 30/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_CMAIN_H
#define PROGETTOTIMERLABORATORIO_CMAIN_H

#include "wx/wx.h"

class cMain : public wxFrame{
public:
    cMain();
    virtual ~cMain();

    wxButton *m_btn1 = nullptr;
    wxButton *m_btn2 = nullptr;
    wxButton *m_btn3 = nullptr;

    void TimerButtonClicked(wxCommandEvent &evt);
    void StopwatchButtonClicked(wxCommandEvent &evt);
    void WDClockButtonClicked(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};


#endif //PROGETTOTIMERLABORATORIO_CMAIN_H
