#include "Warlock.h"

Warlock::Warlock(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana, attacker) {
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("SurgeOfLightning", new SurgeOfLightning(30, 30, this)));
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("HealFriend", new HealFriend(15, 15, this)));
        this->magicAbility = new MagicAbility(this, this->spellBook["SurgeOfLightning"]);
        this->ability = new DefaultAbility(this);
}

Warlock::~Warlock() {}

Demon* Warlock::callDemons() {
    return new Demon("Simple Demon", 9, 2);
}

void Warlock::callDemons(int qt, Demon* demons[]) {
    for ( int i = 0; i < qt; i++ ) {
        demons[i] = new Demon("Simple Demon", 9, 2);
    }
}
