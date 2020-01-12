#include "Ability.h"

Ability::Ability(Unit* owner) : owner(owner) {
    std::cout << "Ability object initialized." << std::endl;
}

Ability::~Ability() {
    std::cout << "Ability object destroyed." << std::endl;
}

void Ability::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
}

void Ability::counterAttack(Unit* enemy) {
    enemy->takeDamage(this->owner->getDamage() / 2);
}