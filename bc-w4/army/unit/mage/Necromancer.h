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
        
        virtual void update(Observable* observable) override;
        
        virtual void cast(Unit* target);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif //NECROMANCER_H
