#pragma once
#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"

class Healer : public SpellCaster {
    public:
        Healer(const char* title, int hitPoints, int damage, int mana);
        virtual ~Healer();
        
        virtual void counterAttack(Unit* enemy) override;
};

#endif //HEALER_H
