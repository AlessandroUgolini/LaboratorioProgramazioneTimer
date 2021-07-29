//
// Created by alessandro on 26/07/21.
//

#include "WDClock.h"
#include "thread"
#include "unistd.h"


WDClock::~WDClock() {

}

WDClock::WDClock() {
    total_seconds=time(0);
    ct= localtime(&total_seconds);
    std::thread(begin());
}

tm *WDClock::getCt() const {
    return ct;
}

void WDClock::refresh() {
    total_seconds=time(0);
    ct= localtime(&total_seconds);
}

void WDClock::begin() {
    while(true) {
        refresh();
        //TODO aggiungere il notify per gli observer
        sleep(1);
    }
}

void WDClock::end() {

}