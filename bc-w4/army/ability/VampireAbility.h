#pragma once
#ifndef VAMPIRE_ABILITY_H
#define VAMPIRE_ABILITY_H

#include "Ability.h"

class VampireAbility : public Ability {
    private:
        int bitePower;
    public:
        VampireAbility(Unit* owner, int bitePower);
        virtual ~VampireAbility();
        
        void attack(Unit* enemy) override;
        void counterAttack(Unit* enemy) override;
};

#endif // VAMPIRE_ABILITY_H
