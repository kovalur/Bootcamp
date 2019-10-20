#ifndef STATE_MAGIC_H
#define STATE_MAGIC_H

#include <iostream>

class StateMagic {
    private:
        int mana;
        int manaLimit;
    public:
        StateMagic(int mana);
        ~StateMagic();
        
        int getMana() const;
        int getManaLimit() const;
};

#endif //STATE_MAGIC_H
