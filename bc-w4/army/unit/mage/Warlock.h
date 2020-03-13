#pragma once
#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../../ability/DefaultAbility.h"
#include "../Demon.h"

class Warlock : public SpellCaster {
    public:
        Warlock(const char* title, int hitPoints, int damage, int mana);
        virtual ~Warlock();
        
        Demon* callDemons();
        void callDemons(int qt, Demon* demons[]);
};

#endif // WARLOCK_H
