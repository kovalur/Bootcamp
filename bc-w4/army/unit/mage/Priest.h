#pragma once
#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../../ability/PriestAbility.h"
#include "../../ability/PriestMagicAbility.h"

class Priest : public SpellCaster {
    public:
        Priest(const char* title, int hitPoints, int damage, int mana);
        virtual ~Priest();
        
        void counterAttack(Unit* enemy) override;
};

#endif // PRIEST_H
