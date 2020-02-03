#pragma once
#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <string>

#include "SpellCaster.h"
#include "../../state/Observer.h"

class Unit;

class Necromancer : public SpellCaster, public Observer {
    public:
        Necromancer(const char* title, int hitPoints, int damage, int mana);
        virtual ~Necromancer();
        
        void update(Observable* observable) override;
        
        void cast(Unit* target) override;
        
        void attack(Unit* enemy) override;
        void counterAttack(Unit* enemy) override;
};

#endif //NECROMANCER_H
