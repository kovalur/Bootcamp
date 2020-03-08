#pragma once
#ifndef STATE_MAGIC_H
#define STATE_MAGIC_H

#include <iostream>
#include "../exceptions.h"

class StateMagic {
    protected:
        int mana;
        int manaLimit;
    public:
        StateMagic(int mana);
        virtual ~StateMagic();
        
        int getMana() const;
        int getManaLimit() const;
        
        void addMana(int renewal);
        void spendMana(int cost);
};

#endif // STATE_MAGIC_H
