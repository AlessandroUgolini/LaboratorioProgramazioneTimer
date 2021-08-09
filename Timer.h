//
// Created by alessandro on 24/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_TIMER_H
#define PROGETTOTIMERLABORATORIO_TIMER_H

#include <chrono>
#include "Subject.h"
#include <wx/wx.h>

class Timer : public wxTimer {
public:

    Timer(wxTextCtrl* bh,wxTextCtrl* bm,wxTextCtrl* bs);

    virtual ~Timer();

    int getHour() const;

    void setHour(int hour);

    int getMin() const;

    void setMin(int min);

    int getSec() const;

    void setSec(int sec);

    bool isRunning() const;

    void setRunning(bool running);

    void start();

    void stop();

    void reset();

    void Notify() override;

    void update();

private:

    std::string extendTime(int time);

    int hour,min,sec;
    bool running;

    wxTextCtrl* bh;
    wxTextCtrl* bm;
    wxTextCtrl* bs;
};

#endif //PROGETTOTIMERLABORATORIO_TIMER_H
