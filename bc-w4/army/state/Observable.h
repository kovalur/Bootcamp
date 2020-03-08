#pragma once
#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <iostream>

class Observer;
class Unit;

class Observable {
    private:
        Unit* owner;
    protected:
        virtual void notify() = 0;
    public:
        Observable(Unit* owner);
        virtual ~Observable();
        
        const Unit* getOwner() const;
        
        virtual void attach(Observer* observer) = 0;
};

#endif // OBSERVABLE_H
