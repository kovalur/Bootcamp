#pragma once
#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../../ability/DefaultAbility.h"

class Healer : public SpellCaster {
    public:
        Healer(const char* title, int hitPoints, int damage, int mana);
        virtual ~Healer();
        
        void counterAttack(Unit* enemy) override;
};

#endif // HEALER_H
