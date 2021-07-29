//
// Created by alessandro on 24/07/21.
//

#include "Timer.h"

Timer::Timer(): hour(0), min(0), sec(0){}

Timer::~Timer(){

}

int Timer::getHour() const {
    return hour;
}

void Timer::setHour(int hour) {
    Timer::hour=hour;
}

int Timer::getMin() const {
    return min;
}

void Timer::setMin(int min) {
    Timer::min=min;
}

int Timer::getSec() const {
    return sec;
}

void Timer::setSec(int sec) {
    Timer::sec=sec;
}

bool Timer::isRunning() const {
    return running;
}

void Timer::setRunning(bool running) {
    Timer::running = running;
}

void Timer::start() {
    Timer::running=true;
    Timer::loop();
}

void Timer::stop() {
    Timer::running=false;
}

void Timer::reset() {
    Timer::running=false;
    Timer::hour=0;
    Timer::min=0;
    Timer::sec=0;
}

void Timer::loop() {
    while(Timer::running){
        Timer::sec--;
        if(Timer::hour==0 && Timer::min==0 && Timer::sec==0){
            Timer::running=false;
        }
        if(Timer::sec<0){
            Timer::sec=59;
            Timer::min--;
        }
        if(Timer::min<0){
            Timer::min=59;
            Timer::hour--;
        }
        //TODO aggiungere lo sleep di 1 secondo
        //TODO aggiungere anche la notifica all'observer
    }
}
