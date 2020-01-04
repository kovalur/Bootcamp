#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Soldier : public Unit {
    public:
        Soldier(const char* title, int hitPoints, int damage);
        virtual ~Soldier();
        
        void takeMagicDamage(int dmg);
};

#endif //SOLDIER_H
