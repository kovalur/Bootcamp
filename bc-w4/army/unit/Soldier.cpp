#include "Soldier.h"

Soldier::Soldier(const char* title, int hitPoints, int damage) : Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    std::cout << "Soldier object initialized." << std::endl;
}

Soldier::~Soldier() {
    std::cout << "Soldier object destroyed." << std::endl;
}
