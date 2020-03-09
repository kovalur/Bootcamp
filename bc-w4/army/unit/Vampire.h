#pragma once
#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "Undead.h"
#include "../ability/VampireAbility.h"

class Vampire : public Unit, public Undead {
    public:
        Vampire(const char* title, int hitPoints, int damage, int bitePower=4);
        virtual ~Vampire();
};

#endif // VAMPIRE_H
