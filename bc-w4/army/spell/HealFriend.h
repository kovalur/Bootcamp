#pragma once
#ifndef HEAL_FRIEND_H
#define HEAL_FRIEND_H

#include "Spell.h"
#include "../unit/mage/SpellCaster.h"

class SpellCaster;

class HealFriend : public Spell {
    public:
        HealFriend(int actionPoints, int cost, SpellCaster* owner);
        virtual ~HealFriend();
        
        virtual void action(Unit* target) override;
};

#endif //HEAL_FRIEND_H
