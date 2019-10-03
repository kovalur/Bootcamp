#include <iostream>
#include <string>
#include "Unit.h"

Unit::Unit(const std::string& name, int hp, int dmg)
    : name(name), hitPoints(hp), hitPointsLimit(hp), damage(dmg) {}

Unit::~Unit() {}

void Unit::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

int Unit::getDamage() const {
    return damage;
}

int Unit::getHitPoints() const {
    return hitPoints;
}

int Unit::getHitPointsLimit() const {
    return hitPointsLimit;
}

const std::string& Unit::getName() const {
    return name;
}

void Unit::addHitPoints(int hp) {
    int newHp = this->hitPoints + hp;
    
    if ( hp <= 0 ) {
        return;
    }
    
    try {
        this->ensureIsAlive();
    } catch (UnitIsDead e) {
        return;
    }
    
    if ( newHp > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints = newHp;
}

void Unit::takeDamage(int dmg) {
    int newHp = this->hitPoints - dmg;
    
    try {
        this->ensureIsAlive();
    } catch (UnitIsDead e) {
        return;
    }
    
    if ( newHp > 0 ) {
        this->hitPoints = newHp;
        return;
    }
    this->hitPoints = 0;
}

void Unit::attack(Unit& enemy) {
    try {
        this->ensureIsAlive();
    } catch (UnitIsDead e) {
        return;
    }
    
    enemy.takeDamage(this->damage);
    if ( enemy.hitPoints > 0 ) {
        this->counterAttack(enemy);
    }
}

void Unit::counterAttack(Unit& enemy) {
    int newHp = this->hitPoints - enemy.damage / 2;
    
    if ( newHp > 0 ) {
        this->hitPoints = newHp;
        return;
    }
    this->hitPoints = 0;
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit name is: " << unit.getName() << '.' << '\n';
    out << " details: " << '\n';
    out << "  * damage: " << unit.getDamage() << ';' << '\n';
    out << "  * hit points: " << unit.getHitPoints() << ';' << '\n';
    out << "  * hit points limit: " << unit.getHitPointsLimit() << '.' << '\n';
    
    return out;
}
