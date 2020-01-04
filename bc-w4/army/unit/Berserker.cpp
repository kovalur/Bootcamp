#include "Berserker.h"

Berserker::Berserker(const char* title, int hitPoints, int damage) : Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    std::cout << "Berserker object initialized." << std::endl;
}

Berserker::~Berserker() {
    std::cout << "Berserker object destroyed." << std::endl;
}

void Berserker::takeMagicDamage(int dmg) {
    throw NoMagicAffectException();
}
