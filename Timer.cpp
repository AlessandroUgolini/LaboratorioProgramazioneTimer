//
// Created by alessandro on 24/07/21.
//

#include <unistd.h>
#include "Timer.h"

Timer::Timer(wxEvtHandler* owner,int id): hour(0), min(0), sec(0) {
    tim=new wxTimer(owner,id);
}

Timer::~Timer(){
}

void Timer::start() {
    if(!Timer::running && !Timer::isZero()) {
        Timer::running = true;
        tim->Start(1000,false);
    }
}

void Timer::stop() {
    if(Timer::running) {
        tim->Stop();
        Timer::running = false;
    }
}

void Timer::reset() {
    tim->Stop();
    Timer::running=false;
    Timer::hour=0;
    Timer::min=0;
    Timer::sec=0;
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
}

std::string Timer::extendTime(int time){
    std::string tString=std::to_string(time);
    if(time<10)
        tString="0"+tString;
    return tString;
}

bool Timer::isZero(){
    if(Timer::hour==0 && Timer::min==0 && Timer::sec==0){
        return true;
    }
    else
        return false;
}



