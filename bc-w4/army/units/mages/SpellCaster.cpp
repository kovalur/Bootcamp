#include "SpellCaster.h"

SpellCaster::SpellCaster(int magicDamage,
                        int damage, int hitPoints, std::string name,
                        int mana) : Unit(damage, hitPoints, name),
                                    stateMagic(new StateMagic(mana)) {
    this->magicDamage = magicDamage;
    std::cout << "SpellCaster object constructed" << std::endl;
}

SpellCaster::~SpellCaster() {
    std::cout << "SpellCaster object destroyed" << std::endl;
    delete(this->stateMagic);
}

int SpellCaster::getMagicDamage() const {
    return this->magicDamage;
}

int SpellCaster::getMana() const {
    return this->stateMagic->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->stateMagic->getManaLimit();
}

void SpellCaster::magicAttack(Unit& enemy) {
    //TODO:
}

void SpellCaster::magicCounterAttack(Unit& enemy) {
    //TODO:
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster) {
    out << "SpellCaster " << spellCaster.getName() << " has " << spellCaster.getHitPoints();
    out << "(" << spellCaster.getHitPointsLimit() << ")" << " hit points, ";
    out << "its damage is " << spellCaster.getDamage();
    out << ", magic mamage is " << spellCaster.getMagicDamage() << ", ";
    out << "and has "<< spellCaster.getMana() << "(" << spellCaster.getManaLimit() << ") of mana.";
}
