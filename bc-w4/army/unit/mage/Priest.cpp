#include "Priest.h"

Priest::Priest(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana, healer) {
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("HealFriend", new HealFriend(20, 20, this)));
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("SurgeOfLightning", new SurgeOfLightning(25, 25, this)));
        this->magicAbility = new PriestMagicAbility(this, this->spellBook["HealFriend"]);
        this->ability = new PriestAbility(this);
}

Priest::~Priest() {}

void Priest::counterAttack(Unit* enemy) {
    if ( this->magicAbility->getSpell()->getSpellType() == attacking ) {
        this->magicAbility->counterAttack(enemy);
    } else {
        this->ability->counterAttack(enemy);
    }
}
