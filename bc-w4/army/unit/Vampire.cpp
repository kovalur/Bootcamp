#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoints, int damage, int bitePower) : Unit(title, hitPoints, damage) {
    this->ability = new VampireAbility(this, bitePower);
    std::cout << "Vampire object initialized." << std::endl;
}

Vampire::~Vampire() {
    std::cout << "Vampire object destroyed." << std::endl;
}

Vampire* Vampire::makeVampire(const Unit* victim) {
    if ( typeid(*victim) != typeid(Werewolf) && typeid(*victim) != typeid(Vampire) ) {
        std::string title = std::string(victim->getTitle()).append(" is made Vampire");
        Vampire* vampire = new Vampire(title.c_str(), int(Hp::Vampire), int(Dmg::Vampire), 4);
        
        delete victim;
        
        return vampire;
    }
    throw NotTurnVampireException();
}
