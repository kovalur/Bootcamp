#include "HealFriend.h"

HealFriend::HealFriend(int actionPoints, int cost, SpellCaster* owner)
                : Spell(actionPoints, cost, "HealFriend", owner, healing) {}

HealFriend::~HealFriend() {}

void HealFriend::action(Unit* target) {
    int actionPoints = this->actionPoints;
    
    if ( this->owner->getMageType() != healer ) {
        actionPoints /= 2;
    }
    target->addHitPoints(this->actionPoints);
}
