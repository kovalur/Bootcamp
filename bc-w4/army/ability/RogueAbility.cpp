#include "RogueAbility.h"

RogueAbility::RogueAbility(Unit* owner) : Ability(owner) {
    std::cout << "RogueAbility object initialized." << std::endl;
}

RogueAbility::~RogueAbility() {
    std::cout << "RogueAbility object destroyed." << std::endl;
}

void RogueAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    enemy->takeDamage(this->owner->getDamage());
}
