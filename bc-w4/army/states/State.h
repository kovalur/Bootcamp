#ifndef STATE_H
#define STATE_H

#include <iostream>

class UnitIsDead {};

class State {
    private:
        int hitPoints;
        int hitPointsLimit;
    public:
        State(int hitPoints);
        ~State();
        
        void ensureIsAlive();
        
        int getHitPoints() const;
        int getHitPointsLimit() const;
        void setHitPoints(int hitPoints);
        void setHitPointsLimit(int hitPointsLimit);
        
        void addHitPoints(int hitPoints);
        void takeDamage(int damage);
};

#endif //STATE_H
