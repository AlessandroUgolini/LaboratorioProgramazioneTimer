//
// Created by alessandro on 26/07/21.
//

#include "Clock.h"


Clock::Clock(wxEvtHandler *handlerC,int id) {

    Clock::sc=std::chrono::system_clock::now();
    tim= new wxTimer(handlerC,id);
    tim->Start(1000,false);
}

Clock::Clock() {
    Clock::sc=std::chrono::system_clock::now();
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

std::string Clock::getTimeString(Format f){
    std::time_t rawTime=Clock::getTime();
    char timeStr [80];
    if(f==Format::H24)
        std::strftime(timeStr,80,"%H:%M:%S",std::localtime(&rawTime));
    if(f==Format::H12)
        std::strftime(timeStr,80,"%I:%M:%S:%p",std::localtime(&rawTime));
    if(f==Format::Date)
        std::strftime(timeStr,80,"%Y-%m-%d",std::localtime(&rawTime));
    return timeStr;
};


