//
// Created by alessandro on 29/07/21.
//

#ifndef PROGETTOTIMERLABORATORIO_SUBJECT_H
#define PROGETTOTIMERLABORATORIO_SUBJECT_H

class Subject {
protected:
    virtual ~Subject() {};

public:
    virtual void registerObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notifyObservers()const =0;
};

#endif //PROGETTOTIMERLABORATORIO_SUBJECT_H
