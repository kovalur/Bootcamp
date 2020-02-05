#pragma once
#ifndef PRIEST_ABILITY_H
#define PRIEST_ABILITY_H

#include "Ability.h"
#include "../unit/Undead.h"

class PriestAbility : public Ability {
    public:
        PriestAbility(Unit* owner);
        virtual ~PriestAbility();
        
        void attack(Unit* enemy) override;
        void counterAttack(Unit* enemy) override;
};

#endif //PRIEST_ABILITY_H
