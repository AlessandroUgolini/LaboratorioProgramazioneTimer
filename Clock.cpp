//
// Created by alessandro on 26/07/21.
//

#include "Clock.h"


Clock::Clock(wxTextCtrl* b24,wxTextCtrl* b12, wxTextCtrl* bDay) {
    tb24=new char[80];
    tb12=new char[80];
    tbday=new char[80];
    Clock::sc=std::chrono::system_clock::now();
    std::time_t now_c=std::chrono::system_clock::to_time_t(sc);
    std::strftime(tb24, 80, "%H:%M:%S", std::localtime(&now_c));
    std::strftime(tb12, 80, "%I:%M:%S:%p", std::localtime(&now_c));
    std::strftime(tbday,80,"%Y-%m-%d",std::localtime(&now_c));
    tBox24=b24;
    tBox12=b12;
    tBoxDay=bDay;
}

Clock::~Clock() {
    delete[] tb24;
    delete[] tb12;
    delete[] tbday;
}

void Clock::Notify() {
    Clock::sc=std::chrono::system_clock::now();
    std::time_t now_c=std::chrono::system_clock::to_time_t(sc);
    std::strftime(tb24, 80, "%H:%M:%S", std::localtime(&now_c));
    std::strftime(tb12, 80, "%I:%M:%S:%p", std::localtime(&now_c));
    std::strftime(tbday,80,"%Y-%m-%d",std::localtime(&now_c));
    tBox24->Replace(0,80,tb24);
    tBox12->Replace(0,80,tb12);
    tBoxDay->Replace(0,80,tbday);
}

char *Clock::getTb24() const {
    return tb24;
}

char *Clock::getTb12() const {
    return tb12;
}

char *Clock::getTbday() const {
    return tbday;
}
