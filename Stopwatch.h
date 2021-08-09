//
// Created by alessandro on 03/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_STOPWATCH_H
#define PROGETTOTIMERLABORATORIO_STOPWATCH_H

#include <wx/wx.h>

class Stopwatch :public wxTimer{
public:
    Stopwatch(wxTextCtrl* bh,wxTextCtrl* bm,wxTextCtrl* bs);
    virtual ~Stopwatch();

    void start();
    void stop();
    void reset();

    void Notify() override;

    void update();

    int getHour() const;
    void setHour(int hour);

    int getMin() const;
    void setMin(int min);

    int getSec() const;
    void setSec(int sec);

    bool isRunning() const;
    void setRunning(bool running);

private:

    std::string extendTime(int time);

    int hour,min,sec;
    bool running;

    wxTextCtrl* bh;
    wxTextCtrl* bm;
    wxTextCtrl* bs;

};


#endif //PROGETTOTIMERLABORATORIO_STOPWATCH_H
