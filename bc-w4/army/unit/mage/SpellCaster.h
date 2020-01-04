#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../Unit.h"
#include "../../ability/DefaultAbility.h"
#include "../../state/StateMagic.h"
#include "../../ability/MagicAbility.h"
#include "../../spell/Spell.h"

class MagicAbility;

class SpellCaster : public Unit {
    protected:
        StateMagic* stateMagic;
        MagicAbility* magicAbility;
    public:
        SpellCaster(const char* title, int hitPoints, int damage, int mana);
        virtual ~SpellCaster();
        
        int getMana() const;
        int getManaLimit() const;
        
        void addMana(int renewal);
        void spendMana(int cost);
        
        void changeSpell(Spell* newSpell);
        virtual void cast(Unit* target);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster);

#endif //SPELL_CASTER_H
