#pragma once
#ifndef PRIEST_MAGIC_ABILITY_H
#define PRIEST_MAGIC_ABILITY_H

#include "MagicAbility.h"

class PriestMagicAbility : public MagicAbility {
    public:
        PriestMagicAbility(SpellCaster* owner, Spell* spell);
        virtual ~PriestMagicAbility();
        
        virtual void cast(Unit* target) override;
        virtual void counterAttack(Unit* enemy) override;
};

#endif //PRIEST_MAGIC_ABILITY_H
