#pragma once
#ifndef SURGE_OF_LIGHTNING_H
#define SURGE_OF_LIGHTNING_H

#include "Spell.h"
#include "../unit/mage/SpellCaster.h"

class SpellCaster;

class SurgeOfLightning : public Spell {
    public:
        SurgeOfLightning(int actionPoints, int cost, SpellCaster* owner);
        virtual ~SurgeOfLightning();
        
        void action(Unit* target) override;
};

#endif //SURGEOFLIGHTNING_H
