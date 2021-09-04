//
// Created by alessandro on 03/08/21.
//

#include <unistd.h>
#include "Stopwatch.h"

Stopwatch::Stopwatch(wxEvtHandler *handlerSW,int id): hour(0), min(0), sec(0) {
    tim=new wxTimer(handlerSW,id);
}

Stopwatch::~Stopwatch() {
}

void Stopwatch::start() {
    if(!Stopwatch::running) {
        Stopwatch::running=true;
        tim->Start(1000,false);
    }
}

void Stopwatch::stop() {
    if(Stopwatch::running) {
        tim->Stop();
        Stopwatch::running = false;
    }
}

void Stopwatch::reset() {
    tim->Stop();
    Stopwatch::running=false;
    Stopwatch::hour=0;
    Stopwatch::min=0;
    Stopwatch::sec=0;
}

int Stopwatch::getHour() const {
    return hour;
}

void Stopwatch::setHour(int hour) {
    Stopwatch::hour = hour;
    update();
}

int Stopwatch::getMin() const {
    return min;
}

void Stopwatch::setMin(int min) {
    Stopwatch::min = min;
    update();
}

int Stopwatch::getSec() const {
    return sec;
}

void Stopwatch::setSec(int sec) {
    Stopwatch::sec = sec;
    update();
}

bool Stopwatch::isRunning() const {
    return running;
}

void Stopwatch::setRunning(bool running) {
    Stopwatch::running = running;
}

std::string Stopwatch::extendTime(int time){
    std::string tString=std::to_string(time);
    if(time<10)
        tString="0"+tString;
    return tString;
}

void Stopwatch::update() {
    if(Stopwatch::sec>59){
        Stopwatch::sec=0;
        Stopwatch::min++;
    }
    if(Stopwatch::min>59){
        Stopwatch::min=0;
        Stopwatch::hour++;
    }
    if(Stopwatch::hour>99){
        Stopwatch::hour=0;
    }
    if(Stopwatch::sec<0){
        Stopwatch::sec=59;
        Stopwatch::min--;
    }
    if(Stopwatch::min<0){
        Stopwatch::min=59;
        Stopwatch::hour--;
    }
    if(Stopwatch::hour<0){
        Stopwatch::hour=99;
    }
}