#include "Ability.h"

Ability::Ability(Unit* owner) : owner(owner) {}

Ability::~Ability() {}

void Ability::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    enemy->takeDamage(this->owner->getDamage());
    if ( enemy->getHitPoints() > 0 ) {
        enemy->counterAttack(this->owner);
    }
}

void Ability::counterAttack(Unit* enemy) {
    enemy->takeDamage(this->owner->getDamage() / 2);
}
