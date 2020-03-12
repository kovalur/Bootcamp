#include "PriestAbility.h"

PriestAbility::PriestAbility(Unit* owner) : Ability(owner) {}

PriestAbility::~PriestAbility() {}

void PriestAbility::attack(Unit* enemy) {
    int damage = this->owner->getDamage();
    
    this->owner->ensureIsAlive();
    
    try {
        dynamic_cast<Undead&>(*enemy);
        
        damage *= 2;
    } catch ( std::bad_cast& bc ) {}
    
    enemy->takeDamage(damage);
    enemy->counterAttack(this->owner);
}

void PriestAbility::counterAttack(Unit* enemy) {
    int damage = this->owner->getDamage();
    
    try {
        dynamic_cast<Undead&>(*enemy);
        
        damage *= 2;
    } catch ( std::bad_cast& bc ) {}
    
    enemy->takeDamage(damage / 2);
}
