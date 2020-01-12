#include "SurgeOfLightning.h"

SurgeOfLightning::SurgeOfLightning(int actionPoints, int cost, SpellCaster* owner)
    : Spell(actionPoints, cost, owner) {
        std::cout << "SurgeOfLightning object initialized." << std::endl;
}

SurgeOfLightning::~SurgeOfLightning() {
    std::cout << "SurgeOfLightning object destroyed." << std::endl;
}

void SurgeOfLightning::action(Unit* target) {
    target->takeMagicDamage(this->actionPoints);
    target->counterAttack(this->owner);
}
