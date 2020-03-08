#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

class Observable;

class Observer {
    public:
        Observer();
        virtual ~Observer();
        
        virtual void update(Observable* observable) = 0;
};

#endif // OBSERVER_H
