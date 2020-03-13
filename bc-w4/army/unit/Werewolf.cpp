#include "Werewolf.h"

Werewolf::Werewolf(const char* title, int hitPoints, int damage) : Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    this->currentState = WerewolfState::werewolf;
    this->wolfExtraHp = int(float(this->getHitPoints()) * 0.3f);
    this->wolfExtraDmg = int(float(this->getDamage()) * 0.2f);
}

Werewolf::~Werewolf() {}

void Werewolf::takeMagicDamage(int dmg) {
    if ( this->currentState == WerewolfState::wolf ) {
        this->state->takeMagicDamage(int(float(dmg) * 1.2f));
    } else {
        this->state->takeMagicDamage(dmg);
    }
}

void Werewolf::transform() {
    if ( this->currentState == WerewolfState::werewolf ) {
        this->state->increaseHp(wolfExtraHp);
        this->state->increaseDamage(wolfExtraDmg);
        this->currentState = WerewolfState::wolf;
    } else {
        if ( this->getHitPoints() > wolfExtraHp ) {
            this->state->decreaseHp(wolfExtraHp);
        } else {
            this->state->decreaseHp(this->getHitPoints()-1);
        }
        this->state->decreaseDamage(wolfExtraDmg);
        this->currentState = WerewolfState::werewolf;
    }
}

Werewolf* Werewolf::makeWerewolf(const Unit* victim) {
    if ( typeid(*victim) != typeid(Vampire) && typeid(*victim) != typeid(Werewolf) ) {
        Werewolf* werewolf = new Werewolf(victim->getTitle(), int(Hp::Werewolf), int(Dmg::Werewolf));
        delete victim;
        
        return werewolf;
    }
    throw NotTurnWerewolfException();
}
