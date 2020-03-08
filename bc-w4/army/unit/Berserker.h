#pragma once
#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"
#include "../exceptions.h"

class Berserker : public Unit {
    public:
        Berserker(const char* title, int hitPoints, int damage);
        virtual ~Berserker();
        
        void takeMagicDamage(int dmg) override;
};

#endif // BERSERKER_H
