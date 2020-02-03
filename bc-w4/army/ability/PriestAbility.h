#pragma once
#ifndef PRIEST_ABILITY_H
#define PRIEST_ABILITY_H

#include "Ability.h"

class PriestAbility : public Ability {
    public:
        PriestAbility(Unit* owner);
        virtual ~PriestAbility();
        
        virtual void attack(Unit* enemy) override;
        virtual void counterAttack(Unit* enemy) override;
};

#endif //PRIEST_ABILITY_H
