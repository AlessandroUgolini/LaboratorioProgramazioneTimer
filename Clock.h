//
// Created by alessandro on 26/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_CLOCK_H
#define PROGETTOTIMERLABORATORIO_CLOCK_H

#include <ctime>
#include "Subject.h"
#include <wx/wx.h>

class Clock : public wxTimer{

public:
    Clock();
    virtual ~Clock();

    tm* getCt() const;

private:
    void refresh();
    void begin();
    void end();

    time_t total_seconds;
    struct tm* ct;
};


#endif //PROGETTOTIMERLABORATORIO_CLOCK_H
