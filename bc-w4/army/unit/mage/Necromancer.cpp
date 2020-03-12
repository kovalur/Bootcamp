#include "Necromancer.h"

Necromancer::Necromancer(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana, attacker) {
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("SurgeOfLightning", new SurgeOfLightning(25, 25, this)));
        this->spellBook.insert(std::pair<std::string, Spell*>
            ("HealFriend", new HealFriend(20, 20, this)));
        this->magicAbility = new MagicAbility(this, this->spellBook["SurgeOfLightning"]);
        this->ability = new DefaultAbility(this);
}

Necromancer::~Necromancer() {}

void Necromancer::update(Observable* observable) {
    int extraHp = observable->getOwner()->getHitPointsLimit() / 5;
    
    this->addHitPoints(extraHp);
}

void Necromancer::cast(Unit* target) {
    this->magicAbility->cast(target);
    
    if ( this->magicAbility->getSpell()->getSpellType() == attacking && target->getHitPoints() > 0 ) {
        target->attach(this); 
    }
}

void Necromancer::attack(Unit* enemy) {
    this->ability->attack(enemy);
    enemy->attach(this);
}

void Necromancer::counterAttack(Unit* enemy) {
    if ( this->magicAbility->getSpell()->getSpellType() == attacking ) {
        this->magicAbility->counterAttack(enemy);
    } else {
        this->ability->counterAttack(enemy);
    }
}
