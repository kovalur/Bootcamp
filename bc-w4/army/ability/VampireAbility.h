#pragma once
#ifndef VAMPIRE_ABILITY_H
#define VAMPIRE_ABILITY_H

#include "Ability.h"

class VampireAbility : public Ability {
    private:
        int biteDamage;
    public:
        VampireAbility(Unit* owner);
        virtual ~VampireAbility();
        
        virtual void attack(Unit* enemy) override;
        virtual void counterAttack(Unit* enemy) override;
};

#endif //VAMPIRE_ABILITY_H
