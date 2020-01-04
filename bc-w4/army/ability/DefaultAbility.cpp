#include "DefaultAbility.h"

DefaultAbility::DefaultAbility(Unit* owner) : Ability(owner) {
    std::cout << "DefaultAbility object initialized." << std::endl;
}

DefaultAbility::~DefaultAbility() {
    std::cout << "DefaultAbility object destroyed." << std::endl;
}

void DefaultAbility::attack(Unit* enemy) {
    this->Ability::attack(enemy);
}
