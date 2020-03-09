#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoints, int damage, int bitePower) : Unit(title, hitPoints, damage) {
    this->ability = new VampireAbility(this, bitePower);
    std::cout << "Vampire object initialized." << std::endl;
}

Vampire::~Vampire() {
    std::cout << "Vampire object destroyed." << std::endl;
}
