#ifndef HEAL_FRIEND_H
#define HEAL_FRIEND_H

#include "Spell.h"

class HealFriend : public Spell {
    public:
        HealFriend(int actionPoints, int cost);
        virtual ~HealFriend();
        
        virtual void action(Unit* target);
};

#endif //HEAL_FRIEND_H
