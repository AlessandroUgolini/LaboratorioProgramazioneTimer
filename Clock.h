//
// Created by alessandro on 26/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_CLOCK_H
#define PROGETTOTIMERLABORATORIO_CLOCK_H

#include <chrono>
#include "Subject.h"
#include <wx/wx.h>

class Clock : public wxTimer{

public:
    Clock(wxTextCtrl* b24,wxTextCtrl* b12, wxTextCtrl* bDay);
    virtual ~Clock();

    void Notify() override;

    char *getTb24() const;

    char *getTb12() const;

    char *getTbday() const;

private:
    std::chrono::time_point<std::chrono::system_clock> sc;
    char* tb24;
    char* tb12;
    char* tbday;
    wxTextCtrl* tBox24;
    wxTextCtrl* tBox12;
    wxTextCtrl* tBoxDay;

};


#endif //PROGETTOTIMERLABORATORIO_CLOCK_H
