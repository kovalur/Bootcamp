#include "Spell.h"

Spell::Spell(int actionPoints, int cost)
    : actionPoints(actionPoints),  cost(cost) {
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
