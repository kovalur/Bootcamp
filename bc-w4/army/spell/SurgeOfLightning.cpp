#include "SurgeOfLightning.h"

SurgeOfLightning::SurgeOfLightning(int actionPoints, int cost, SpellCaster* owner)
    : Spell(actionPoints, cost, "SurgeOfLightning", owner, attacking) {}

SurgeOfLightning::~SurgeOfLightning() {}

void SurgeOfLightning::action(Unit* target) {
    int actionPoints = this->actionPoints;
    
    if ( this->owner->getMageType() != attacker ) {
        actionPoints /= 2;
    }
    target->takeMagicDamage(actionPoints);
    if ( target->getHitPoints() > 0 ) {
        target->counterAttack(this->owner);
    }
}
