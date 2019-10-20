#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include "../states/State.h"

class Unit {
    private:
        int damage;
        std::string name;
    public:
        State* state;
        Unit(int damage, int hitPoints, std::string name = "Default Unit");
        ~Unit();
        
        std::string getName() const;
        int getDamage() const;
        
        virtual void counterAttack(Unit& enemy);
        virtual void attack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
