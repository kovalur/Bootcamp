#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* owner) : Ability(owner) {
    this->biteDamage = this->owner->getDamage() / 4;
    std::cout << "VampireAbility object initialized." << std::endl;
}

VampireAbility::~VampireAbility() {
    std::cout << "VampireAbility object destroyed." << std::endl;
}

void VampireAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    enemy->takeDamage(this->owner->getDamage());
    enemy->takeDamage(this->biteDamage);
    enemy->counterAttack(this->owner);
}

void VampireAbility::counterAttack(Unit* enemy) {
    enemy->takeDamage(this->owner->getDamage() / 2);
    enemy->takeDamage(this->biteDamage);
}
