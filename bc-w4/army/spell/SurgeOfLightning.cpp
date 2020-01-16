#include "SurgeOfLightning.h"

SurgeOfLightning::SurgeOfLightning(int actionPoints, int cost, SpellCaster* owner)
    : Spell(actionPoints, cost, "SurgeOfLightning", owner, attacking) {
        std::cout << "SurgeOfLightning object initialized." << std::endl;
}

SurgeOfLightning::~SurgeOfLightning() {
    std::cout << "SurgeOfLightning object destroyed." << std::endl;
}

void SurgeOfLightning::action(Unit* target) {
    int actionPoints = this->actionPoints;
    
    if ( this->owner->getMageType() != attacker ) {
        actionPoints /= 2;
    }
    target->takeMagicDamage(actionPoints);
    target->counterAttack(this->owner);
}
