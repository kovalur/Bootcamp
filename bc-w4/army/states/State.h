#ifndef STATE_H
#define STATE_H

#include <iostream>

class UnitIsDead {};

class State {
    protected:
        int hitPoints;
        int hitPointsLimit;
    public:
        State(int hitPoints);
        ~State();
        
        int getHitPoints() const;
        int getHitPointsLimit() const;
        void setHitPoints(int hitPoints);
        void setHitPointsLimit(int hitPointsLimit);
        
        void ensureIsAlive();
        
        void addHitPoints(int hitPoints);
        void takeDamage(int damage);
};

#endif //STATE_H
