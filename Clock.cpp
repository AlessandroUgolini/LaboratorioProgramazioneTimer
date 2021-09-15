//
// Created by alessandro on 26/07/21.
//

#include "Clock.h"


Clock::Clock(wxEvtHandler *handlerC,int id) {

    Clock::sc=std::chrono::system_clock::now();
    std::time_t now_c=std::chrono::system_clock::to_time_t(sc);
    tim= new wxTimer(handlerC,id);
    tim->Start(1000,false);
}

Clock::Clock() {
    Clock::sc=std::chrono::system_clock::now();
    std::time_t now_c=std::chrono::system_clock::to_time_t(sc);
    tim= new wxTimer;
}

Clock::~Clock() {
    tim->Stop();
    tim->~wxTimer();
}

std::time_t Clock::getTime(){
    sc=std::chrono::system_clock::now();
    std::time_t now_c=std::chrono::system_clock::to_time_t(sc);
    return now_c;
}

std::string Clock::getTime24(){
    std::time_t rawTime=Clock::getTime();
    char time24 [80];
    std::strftime(time24, 80, "%H:%M:%S", std::localtime(&rawTime));
    return time24;
}

std::string Clock::getTime12(){

    std::time_t rawTime=Clock::getTime();
    char time12 [80];
    std::strftime(time12, 80, "%I:%M:%S:%p", std::localtime(&rawTime));
    return time12;
}

std::string Clock::getTimeDay(){
    std::time_t rawTime=Clock::getTime();
    char timeDay [80];
    std::strftime(timeDay,80,"%Y-%m-%d",std::localtime(&rawTime));
    return timeDay;
}




