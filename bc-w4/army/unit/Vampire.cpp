#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoints, int damage, int bitePower) : Unit(title, hitPoints, damage) {
    this->ability = new VampireAbility(this, bitePower);
}

Vampire::~Vampire() {}

Vampire* Vampire::makeVampire(const Unit* victim) {
    if ( typeid(*victim) != typeid(Werewolf) && typeid(*victim) != typeid(Vampire) ) {
        Vampire* vampire = new Vampire(victim->getTitle(), int(Hp::Vampire), int(Dmg::Vampire), 4);
        delete victim;
        
        return vampire;
    }
    throw NotTurnVampireException();
}
