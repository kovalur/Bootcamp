#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"

class SpellCaster;

enum TypeOfSpell { healing, attacking };

class Spell {
    protected:
        int actionPoints;
        int cost;
        const char* spellName;
        TypeOfSpell spellType;
        SpellCaster* owner;
    public:
        Spell(int actionPoints, int cost, const char* spellName, SpellCaster* owner, TypeOfSpell spellType);
        virtual ~Spell();
        
        int getActionPoints() const;
        int getCost() const;
        const char* getSpellName() const;
        TypeOfSpell getSpellType() const;
        
        virtual void action(Unit* target) = 0;
};

#endif //SPELL_H
