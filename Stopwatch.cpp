//
// Created by alessandro on 03/08/21.
//

#include <unistd.h>
#include "Stopwatch.h"

Stopwatch::Stopwatch() {}

Stopwatch::~Stopwatch() {

}

void Stopwatch::start() {
    if(!Stopwatch::running) {
        Stopwatch::running=true;
        Stopwatch::loop();
    }
}

void Stopwatch::stop() {

}

void Stopwatch::reset() {

}

int Stopwatch::getHour() const {
    return hour;
}

void Stopwatch::setHour(int hour) {
    Stopwatch::hour = hour;
}

int Stopwatch::getMin() const {
    return min;
}

void Stopwatch::setMin(int min) {
    Stopwatch::min = min;
}

int Stopwatch::getSec() const {
    return sec;
}

void Stopwatch::setSec(int sec) {
    Stopwatch::sec = sec;
}

bool Stopwatch::isRunning() const {
    return running;
}

void Stopwatch::setRunning(bool running) {
    Stopwatch::running = running;
}

void Stopwatch::loop() {
    while(Stopwatch::running) {
        Stopwatch::sec++;

        if (Stopwatch::sec == 60) {
            Stopwatch::sec = 0;
            Stopwatch::min++;
        }
        if (Stopwatch::min == 60) {
            Stopwatch::min = 0;
            Stopwatch::hour++;
        }
        sleep(1);
        //TODO aggiungere anche la notifica all'observer
    }
    return;
}