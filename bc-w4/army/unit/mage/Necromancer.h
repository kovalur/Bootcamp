#pragma once
#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"
#include "../../ability/DefaultAbility.h"
#include "../Undead.h"
#include "../../state/Observer.h"

#include <string>

class Unit;

class Necromancer : public SpellCaster, public Observer, public Undead {
    public:
        Necromancer(const char* title, int hitPoints, int damage, int mana);
        virtual ~Necromancer();
        
        void update(Observable* observable) override;
        
        void cast(Unit* target) override;
        
        void attack(Unit* enemy) override;
};

#endif // NECROMANCER_H
