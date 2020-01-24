#include "Demon.h"

Demon::Demon(const char* title, int hitPoints, int damage)
    : Soldier(title, hitPoints, damage) {
    std::cout << "Demon object initialized." << std::endl;
}

Demon::~Demon() {
    std::cout << "Demon object destroyed." << std::endl;
}

void Demon::addHitPoints(int hp) {
    throw UnitHealNotAllowedException();
}
