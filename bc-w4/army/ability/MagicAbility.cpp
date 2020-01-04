#include "MagicAbility.h"

MagicAbility::MagicAbility(SpellCaster* owner, Spell* spell) : owner(owner), spell(spell) {
    std::cout << "MagicAbility object initialized." << std::endl;
}

MagicAbility::~MagicAbility() {
    delete(this->spell);
    std::cout << "MagicAbility object destroyed." << std::endl;
}

void MagicAbility::changeSpell(Spell* newSpell) {
    delete(this->spell);
    this->spell = newSpell;
}

void MagicAbility::cast(Unit* target) {
    this->owner->ensureIsAlive();
    
    this->owner->spendMana(this->spell->getCost());
    this->spell->action(target);
}

void MagicAbility::counterAttack(Unit* enemy) {
    this->owner->spendMana(this->spell->getCost() / 2);
    enemy->takeDamage(this->spell->getActionPoints() / 2);
}
