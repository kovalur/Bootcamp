#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* owner, int bitePower) : Ability(owner), bitePower(bitePower) {
    std::cout << "VampireAbility object initialized." << std::endl;
}

VampireAbility::~VampireAbility() {
    std::cout << "VampireAbility object destroyed." << std::endl;
}

void VampireAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    int hpTaken = (enemy->getHitPointsLimit() * this->bitePower) / 100;
    
    enemy->takeDamage(this->owner->getDamage());
    enemy->takeDamage(hpTaken);
    this->owner->addHitPoints(hpTaken);
    enemy->counterAttack(this->owner);
}

void VampireAbility::counterAttack(Unit* enemy) {
    int hpTaken = (enemy->getHitPointsLimit() * this->bitePower) / 100;
    
    enemy->takeDamage(this->owner->getDamage() / 2);
    enemy->takeDamage(hpTaken);
    this->owner->addHitPoints(hpTaken);
}
