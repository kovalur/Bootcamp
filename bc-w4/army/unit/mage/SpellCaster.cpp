#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* title, int hitPoints, int damage, int mana, TypeOfMage mageType)
    : Unit(title, hitPoints, damage),
        stateMagic(new StateMagic(mana)), mageType(mageType) {
            std::cout << "SpellCaster object initialized." << std::endl;
}

SpellCaster::~SpellCaster() {
    delete this->magicAbility;
    delete this->stateMagic;
    std::cout << "SpellCaster object destroyed." << std::endl;
}

int SpellCaster::getMana() const {
    return this->stateMagic->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->stateMagic->getManaLimit();
}

TypeOfMage SpellCaster::getMageType() const {
    return this->mageType;
}

const char* SpellCaster::getActiveSpellName() const {
    return this->magicAbility->getSpellName();
}

void SpellCaster::addMana(int renewal) {
    this->stateMagic->addMana(renewal);
}

void SpellCaster::spendMana(int cost) {
    this->stateMagic->spendMana(cost);
}

void SpellCaster::changeSpell(const char* spellName) {
    this->spellBookIt = this->spellBook.find(spellName);
    
    if ( this->spellBookIt == this->spellBook.end() ) {
        throw NoSuchSpellException();
    }
    this->magicAbility->changeSpell(this->spellBookIt->second);
}

void SpellCaster::cast(Unit* target) {
    this->magicAbility->cast(target);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster) {
    out << "SpellCaster " << spellCaster.getTitle() << " has " << spellCaster.getHitPoints();
    out << "(" << spellCaster.getHitPointsLimit() << ")" << " hit points, ";
    out << "its damage is " << spellCaster.getDamage() << ". ";
    out << "It has " << spellCaster.getMana();
    out << "(" << spellCaster.getManaLimit() << ")" << " mana.";
};
