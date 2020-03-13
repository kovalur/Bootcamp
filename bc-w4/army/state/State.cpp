#include "State.h"
#include "../exceptions.h"
#include <iostream>

State::State(const char* title, int hitPoints, int damage)
    : title(title), hitPoints(hitPoints), hitPointsLimit(hitPoints), damage(damage) {}

State::~State() {}

void State::ensureIsAlive() {
    if (this->hitPoints == 0) {
        throw UnitIsDeadException();
    };
}

const char* State::getTitle() const {
    return this->title;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

int State::getDamage() const {
    return this->damage;
}

void State::addHitPoints(int hp) {
    this->ensureIsAlive();
    
    int total = this->hitPoints + hp;
    if ( total > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints = total;
}

void State::increaseHp(int extraHp) {
    this->ensureIsAlive();
    
    if ( extraHp > 0 ) {
        this->hitPointsLimit += extraHp;
        this->addHitPoints(extraHp);
    }
}

void State::decreaseHp(int hp) {
    this->ensureIsAlive();
    
    if ( hp > 0 ) {
        this->hitPointsLimit -= hp;
        this->_takeDamage(hp);
    }
}

void State::increaseDamage(int extraDmg) {
    this->ensureIsAlive();
    
    if ( extraDmg > 0 ) {
        this->damage += extraDmg;
    }
}

void State::decreaseDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > 0 ) {
        this->damage -= dmg;
    }
}

void State::_takeDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}

void State::takeDamage(int dmg) {
    this->_takeDamage(dmg);
}

void State::takeMagicDamage(int dmg) {
    this->_takeDamage(dmg);
}
