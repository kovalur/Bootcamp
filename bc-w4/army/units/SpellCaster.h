#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H
#include "Unit.h"
#include "../states/StateMagic.h"

#include <iostream>

class SpellCaster : public Unit {
    private:
        int magicDamage;
    public:
        StateMagic* stateMagic;
        SpellCaster(int magicDamage,
                    int damage, int hitPoints, std::string name, int mana);
        ~SpellCaster();
        
        int getMagicDamage() const;
        
        void magicAttack(Unit& enemy);
        void magicCounterAttack(Unit& enemy);
        
        // counterAttack(Unit& enemy);
        // attack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& sellCaster);

#endif //SPELL_CASTER_H
