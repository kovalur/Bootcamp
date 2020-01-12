#include "Spell.h"

Spell::Spell(int actionPoints, int cost, SpellCaster* owner)
    : actionPoints(actionPoints),  cost(cost), owner(owner) {
    std::cout << "Spell object initialized." << std::endl;
}

Spell::~Spell() {
    std::cout << "Spell object destroyed." << std::endl;
}

Spell::getActionPoints() const {
    return this->actionPoints;
}

Spell::getCost() const {
    return this->cost;
}
