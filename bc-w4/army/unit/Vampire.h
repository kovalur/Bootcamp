#pragma once
#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "Undead.h"
#include "Werewolf.h"
#include "../ability/VampireAbility.h"
#include "../properties.h"

#include <string>

class Vampire : public Unit, public Undead {
    public:
        Vampire(const char* title, int hitPoints, int damage, int bitePower=4);
        virtual ~Vampire();
        
        Vampire* makeVampire(const Unit* victim);
};

#endif // VAMPIRE_H
