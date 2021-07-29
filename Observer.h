//
// Created by alessandro on 29/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_OBSERVER_H
#define PROGETTOTIMERLABORATORIO_OBSERVER_H

class Observer{
protected:
    virtual ~Observer() {};

public:
    virtual void update()=0;
};
#endif //PROGETTOTIMERLABORATORIO_OBSERVER_H
