//
// Created by alessandro on 26/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_CLOCK_H
#define PROGETTOTIMERLABORATORIO_CLOCK_H

#include <chrono>
#include <wx/wx.h>

class Clock{

public:
    Clock(wxEvtHandler *handlerC,int id);
    Clock();

    virtual ~Clock();

    std::string getTime24();
    std::string getTime12();
    std::string getTimeDay();

    std::time_t getTime();

private:

    std::chrono::time_point<std::chrono::system_clock> sc;
    wxTimer* tim;
};


#endif //PROGETTOTIMERLABORATORIO_CLOCK_H
