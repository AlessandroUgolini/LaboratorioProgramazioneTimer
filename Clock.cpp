//
// Created by alessandro on 26/07/21.
//

#include "Clock.h"
#include "thread"
#include "unistd.h"


Clock::~Clock() {

}

Clock::Clock() {
    total_seconds=time(0);
    ct= localtime(&total_seconds);
    std::thread(begin());
}

tm *Clock::getCt() const {
    return ct;
}

void Clock::refresh() {
    total_seconds=time(0);
    ct= localtime(&total_seconds);
}

void Clock::begin() {
    while(true) {
        refresh();
        //TODO aggiungere il notify per gli observer
        sleep(1);
    }
}

void Clock::end() {

}