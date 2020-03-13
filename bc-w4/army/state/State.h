#pragma once
#ifndef STATE_H
#define STATE_H

#include "../exceptions.h"

class State {
    private:
        void _takeDamage(int dmg);
    protected:
        const char* title;
        int hitPoints;
        int hitPointsLimit;
        int damage;
    public:
        State(const char* title, int hitPoints, int damage);
        virtual ~State();
        
        void ensureIsAlive();
        
        const char* getTitle() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        
        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
        void increaseHp(int extraHp);
        void decreaseHp(int extraHp);
        void increaseDamage(int extraDmg);
        void decreaseDamage(int dmg);
};

#endif // STATE_H
