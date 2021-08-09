//
// Created by alessandro on 24/07/21.
//

#include <unistd.h>
#include "Timer.h"

Timer::Timer(wxTextCtrl* bh,wxTextCtrl* bm,wxTextCtrl* bs): hour(0), min(0), sec(0){
    this->bh=bh;
    this->bm=bm;
    this->bs=bs;
}

Timer::~Timer(){

}

int Timer::getHour() const {
    return hour;
}

void Timer::setHour(int hour) {
    Timer::hour=hour;
    update();
}

int Timer::getMin() const {
    return min;
}

void Timer::setMin(int min) {
    Timer::min=min;
    update();
}

int Timer::getSec() const {
    return sec;
}

void Timer::setSec(int sec) {
    Timer::sec=sec;
    update();
}

bool Timer::isRunning() const {
    return running;
}

void Timer::setRunning(bool running) {
    Timer::running = running;
}

void Timer::start() {
    if(!Timer::running) {
        Timer::running = true;
        Start(1000,false);
    }
}

void Timer::stop() {
    if(Timer::running) {
        Stop();
        Timer::running = false;
    }
}

void Timer::reset() {
    Stop();
    Timer::running=false;
    Timer::hour=0;
    Timer::min=0;
    Timer::sec=0;
    update();
}

void Timer::Notify() {
    if(Timer::running){
        if(Timer::hour==0 && Timer::min==0 && Timer::sec==0){
            Timer::stop();
        }
        else {
            Timer::sec--;
            update();
        }

    }

}

void Timer::update() {
    if(Timer::sec>59){
        Timer::sec=0;
        Timer::min++;
    }
    if(Timer::min>59){
        Timer::min=0;
        Timer::hour++;
    }
    if(Timer::hour>99){
        Timer::hour=0;
    }
    if(Timer::sec<0){
        Timer::sec=59;
        Timer::min--;
    }
    if(Timer::min<0){
        Timer::min=59;
        Timer::hour--;
    }
    if(Timer::hour<0){
        Timer::hour=99;
    }
    bh->Replace(0,80,extendTime(getHour()));
    bm->Replace(0,80,extendTime(getMin()));
    bs->Replace(0,80,extendTime(getSec()));
}

