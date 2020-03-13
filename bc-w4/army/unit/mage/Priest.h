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
};

#endif // PRIEST_H
