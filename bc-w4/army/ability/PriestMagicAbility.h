#pragma once
#ifndef PRIEST_MAGIC_ABILITY_H
#define PRIEST_MAGIC_ABILITY_H

#include "MagicAbility.h"

class PriestMagicAbility : public MagicAbility {
    public:
        PriestMagicAbility(SpellCaster* owner, Spell* spell);
        virtual ~PriestMagicAbility();
        
        void cast(Unit* target) override;
        void counterAttack(Unit* enemy) override;
};

#endif //PRIEST_MAGIC_ABILITY_H
