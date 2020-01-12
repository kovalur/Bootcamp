#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoints, int damage) : Unit(title, hitPoints, damage) {
    this->ability = new VampireAbility(this);
    std::cout << "Vampire object initialized." << std::endl;
}

Vampire::~Vampire() {
    std::cout << "Vampire object destroyed." << std::endl;
}
