#ifndef SURGE_OF_LIGHTNING_H
#define SURGE_OF_LIGHTNING_H

#include "Spell.h"
#include "../unit/mage/SpellCaster.h"

class SpellCaster;

class SurgeOfLightning : public Spell {
    protected:
        SpellCaster* owner;
    public:
        SurgeOfLightning(int actionPoints, int cost, SpellCaster* owner);
        virtual ~SurgeOfLightning();
        
        virtual void action(Unit* target);
};

#endif //SURGEOFLIGHTNING_H
