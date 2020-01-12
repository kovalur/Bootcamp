#include "Werewolf.h"

Werewolf::Werewolf(const char* title, int hitPoints, int damage) : Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    this->currentState = werewolf;
    this->wolfExtraHp = this->getHitPoints() * 0.3;
    this->wolfExtraDmg = this->getDamage() * 0.2;
    std::cout << "Werewolf object initialized." << std::endl;
}

Werewolf::~Werewolf() {
    std::cout << "Werewolf object destroyed." << std::endl;
}

void Werewolf::takeMagicDamage(int dmg) {
    if ( this->currentState == wolf ) { 
        this->state->takeMagicDamage(dmg * 1.2);
    } else {
        this->state->takeMagicDamage(dmg);
    }
}

void Werewolf::transform() {
    if ( this->currentState == werewolf ) {
        this->state->increaseHp(wolfExtraHp);
        this->state->increaseDamage(wolfExtraDmg);
        this->currentState = wolf;
    } else {
        this->state->decreaseHp(wolfExtraHp);
        this->state->decreaseDamage(wolfExtraDmg);
        this->currentState = werewolf;
    }
}
