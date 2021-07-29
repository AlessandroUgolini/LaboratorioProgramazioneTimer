//
// Created by alessandro on 26/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_WDCLOCK_H
#define PROGETTOTIMERLABORATORIO_WDCLOCK_H

#include <ctime>

class WDClock {

public:
    WDClock();
    virtual ~WDClock();

    tm* getCt() const;

private:
    void refresh();
    void begin();
    void end();

    time_t total_seconds;
    struct tm* ct;
};


#endif //PROGETTOTIMERLABORATORIO_WDCLOCK_H
