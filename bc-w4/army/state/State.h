#ifndef STATE_H
#define STATE_H

#include "../exceptions.h"

class State {
    protected:
        const char* title;
        int hitPoints;
        int hitPointsLimit;
        int damage;
        
        void _takeDamage(int dmg);
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
        void decreaseDamage(int extraDmg);
};

#endif //STATE_H
