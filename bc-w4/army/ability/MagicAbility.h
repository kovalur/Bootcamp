#ifndef MAGIC_ABILITY_H
#define MAGIC_ABILITY_H

#include "../unit/mage/SpellCaster.h"
#include "../spell/Spell.h"

class SpellCaster;

class MagicAbility {
    protected:
        SpellCaster* owner;
        Spell* spell;
    public:
        MagicAbility(SpellCaster* owner, Spell* spell);
        virtual ~MagicAbility();
        
        const Spell* getSpell() const;
        const char* getSpellName() const;
        
        void changeSpell(Spell* newSpell);
        virtual void cast(Unit* target);
        virtual void counterAttack(Unit* enemy);
};

#endif //MAGIC_ABILITY_H
