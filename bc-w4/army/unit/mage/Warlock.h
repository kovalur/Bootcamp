#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>

#include "SpellCaster.h"
#include "../Demon.h"

class Warlock : public SpellCaster {
    public:
        Warlock(const char* title, int hitPoints, int damage, int mana);
        virtual ~Warlock();
        
        Demon* callDemons();
        void callDemons(int qt, Demon* demons[]);
        virtual void counterAttack(Unit* enemy);
};

#endif //WARLOCK_H
