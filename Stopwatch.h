//
// Created by alessandro on 03/08/21.
//

#ifndef PROGETTOTIMERLABORATORIO_STOPWATCH_H
#define PROGETTOTIMERLABORATORIO_STOPWATCH_H


class Stopwatch {
public:
    Stopwatch();
    virtual ~Stopwatch();
    void start();
    void stop();
    void reset();

    int getHour() const;
    void setHour(int hour);

    int getMin() const;
    void setMin(int min);

    int getSec() const;
    void setSec(int sec);

    bool isRunning() const;
    void setRunning(bool running);

private:

    void loop();

    int hour,min,sec;
    bool running;

};


#endif //PROGETTOTIMERLABORATORIO_STOPWATCH_H
