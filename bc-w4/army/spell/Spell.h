#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"

class Spell {
    protected:
        int actionPoints;
        int cost;
    public:
        Spell(int actionPoints, int cost);
        virtual ~Spell();
        
        int getActionPoints() const;
        int getCost() const;
        
        virtual void action(Unit* target) = 0;
};

#endif //SPELL_H
