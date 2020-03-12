#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana, attacker) {
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("SurgeOfLightning", new SurgeOfLightning(30, 30, this)));
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("HealFriend", new HealFriend(15, 15, this)));
        this->magicAbility = new MagicAbility(this, this->spellBook["SurgeOfLightning"]);
        this->ability = new DefaultAbility(this);
}

Wizard::~Wizard() {}

void Wizard::counterAttack(Unit* enemy) {
    if ( this->magicAbility->getSpell()->getSpellType() == attacking ) {
        this->magicAbility->counterAttack(enemy);
    } else {
        this->ability->counterAttack(enemy);
    }
}
