#include "State.h"

State::State(int hitPoints) {
    this->hitPoints = hitPoints;
    this->hitPointsLimit = hitPoints;
    std::cout << "State object constructed" << std::endl;
}

State::~State() {
    std::cout << "State object destroyed" << std::endl;
}

void State::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

void State::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}

void State::setHitPointsLimit(int hitPointsLimit) {
    this->hitPointsLimit = hitPointsLimit;
}

void State::addHitPoints(int hitPoints) {
    int newHitPoints = this->hitPoints + hitPoints;
    
    this->ensureIsAlive();
    
    if ( hitPoints <= 0 ) return;
    
    if ( newHitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints = newHitPoints;
}

void State::takeDamage(int damage) {
    int newHitPoints = this->hitPoints - damage;
    
    this->ensureIsAlive();
    
    if ( newHitPoints < 0 ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= damage;
}
