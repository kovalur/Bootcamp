#pragma once
#ifndef DEMON_H
#define DEMON_H

#include <iostream>

#include "Soldier.h"
#include "../exceptions.h"

class Demon : public Soldier {
    public:
        Demon(const char* title, int hitPoints, int damage);
        virtual ~Demon();
        
        void addHitPoints(int hp) override;
};

#endif // DEMON_H
