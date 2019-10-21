#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H
#include "../Unit.h"
#include "../../states/StateMagic.h"

#include <iostream>

class SpellCaster : public Unit {
    protected:
        StateMagic* stateMagic;
    private:
        int magicDamage;
    public:
        SpellCaster(int magicDamage,
                    int damage, int hitPoints, std::string name, int mana);
        ~SpellCaster();
        
        int getMagicDamage() const;
        
        // wrappers over magic state getters
        int getMana() const;
        int getManaLimit() const;
        
        void magicAttack(Unit& enemy);
        void magicCounterAttack(Unit& enemy);
        
        // counterAttack(Unit& enemy);
        // attack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& sellCaster);

#endif //SPELL_CASTER_H
