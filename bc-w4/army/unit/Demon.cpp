#include "Demon.h"

Demon::Demon(const char* title, int hitPoints, int damage)
    : Soldier(title, hitPoints, damage) {}

Demon::~Demon() {}

void Demon::addHitPoints(int hp) {
    throw UnitHealNotAllowedException();
}
