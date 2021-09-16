//
// Created by alessandro on 03/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_STOPWATCH_H
#define PROGETTOTIMERLABORATORIO_STOPWATCH_H

#include <wx/wx.h>

class Stopwatch{
public:
    Stopwatch(wxEvtHandler *handlerSW,int id);
    virtual ~Stopwatch();

    void start();
    void stop();
    void reset();

    void update();

    int getHour() const;
    void setHour(int hour);

    int getMin() const;
    void setMin(int min);

    int getSec() const;
    void setSec(int sec);

    bool isRunning() const;

    std::string extendTime(int time);

private:

    wxTimer* tim;
    int hour,min,sec;
    bool running;
};


#endif //PROGETTOTIMERLABORATORIO_STOPWATCH_H
