#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../ability/RogueAbility.h"

class Rogue : public Unit {
    public:
        Rogue(const char* title, int hitPoints, int damage);
        virtual ~Rogue();
        
        void takeMagicDamage(int dmg);
};

#endif //ROGUE_H
