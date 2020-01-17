#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <typeinfo>

#include "../state/State.h"
#include "../ability/Ability.h"
#include "../unit/Undead.h"

class Ability;

class Unit {
    protected:
        State* state;
        Ability* ability;
    public:
        Unit(const char* title, int hitPoints, int damage);
        virtual ~Unit();
        
        void ensureIsAlive();
        
        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        
        void addHitPoints(int hp);
        void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        
        virtual void counterAttack(Unit* enemy);
        virtual void attack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
