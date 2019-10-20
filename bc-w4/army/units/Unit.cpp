#include "Unit.h"

Unit::Unit(int damage, int hitPoints, std::string name)
            : state(new State(hitPoints)) {
    this->name = name;
    this->damage = damage;
    std::cout << "Unit object constructed" << std::endl;
}

Unit::~Unit() {
    std::cout << "Unit object destroyed" << std::endl;
    delete(this->state);
}

std::string Unit::getName() const {
    return this->name;
}

int Unit::getDamage() const {
    return this->damage;
}

void Unit::counterAttack(Unit& enemy) {
    int newHitPoints = this->state->getHitPoints() - enemy.damage / 2;
    
    if ( newHitPoints < 0 ) {
        this->state->setHitPoints(0);
        return;
    }
    this->state->setHitPoints(newHitPoints);
}

void Unit::attack(Unit& enemy) {
    this->state->ensureIsAlive();
    
    enemy.state->takeDamage(this->damage);
    
    if ( enemy.state->getHitPoints() > 0 ) {
        this->counterAttack(enemy);
    }
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit " << unit.getName() << " has " << unit.state->getHitPoints();
    out << "(" << unit.state->getHitPointsLimit() << ")" << " hit points, ";
    out << "its damage is " << unit.getDamage() << ".";
}
