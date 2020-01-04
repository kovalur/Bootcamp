#include "Rogue.h"

Rogue::Rogue(const char* title, int hitPoints, int damage) : Unit(title, hitPoints, damage) {
    this->ability = new RogueAbility(this);
    std::cout << "Rogue object initialized." << std::endl;
}

Rogue::~Rogue() {
    std::cout << "Rogue object destroyed." << std::endl;
}

void Rogue::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);
}
