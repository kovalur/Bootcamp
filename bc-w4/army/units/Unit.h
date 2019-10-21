#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include "../states/State.h"

class Unit {
    protected:
        State* state;
    private:
        int damage;
        std::string name;
    public:
        Unit(int damage, int hitPoints, std::string name = "Default Unit");
        ~Unit();
        
        std::string getName() const;
        int getDamage() const;
        
        // wrappers over state getters and setters
        int getHitPoints() const;
        int getHitPointsLimit() const;
        void setHitPoints(int hitPoints);
        void setHitPointsLimit(int hitPointsLimit);
        
        virtual void counterAttack(Unit& enemy);
        virtual void attack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
