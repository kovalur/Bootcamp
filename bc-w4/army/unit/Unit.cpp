#include "Unit.h"

Unit::Unit(const char* title, int hitPoints, int damage)
    : state(new State(title, hitPoints, damage)), Observable(this) {
        std::cout << "Unit object initialized." << std::endl;
}

Unit::~Unit() {
    delete this->state;
    delete this->ability;
    std::cout << "Unit object destroyed." << std::endl;
}

void Unit::ensureIsAlive() {
    return this->state->ensureIsAlive();
}

const char* Unit::getTitle() const {
    return this->state->getTitle();
}

int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}

int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
    this->state->takeDamage(dmg);
    
    if ( this->state->getHitPoints() == 0 ) {
        this->notify();
    }
}

void Unit::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);
    
    if ( this->state->getHitPoints() == 0 ) {
        this->notify();
    }
}

void Unit::attack(Unit* enemy) {
    this->ability->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
    this->ability->counterAttack(enemy);
}

void Unit::attach(Observer* observer) {  
    this->observers.insert(observer);
}

void Unit::notify() {
    std::set<Observer*>::iterator it;
    
    for ( it = this->observers.begin(); it != this->observers.end(); it++ ) {
        (*it)->update(this);
    }
    this->observers.clear();
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit " << unit.getTitle() << " has " << unit.getHitPoints();
    out << "(" << unit.getHitPointsLimit() << ")" << " hit points, ";
    out << "its damage is " << unit.getDamage() << ".";
}
