#include "Spell.h"

Spell::Spell(int actionPoints, int cost, const char* spellName, SpellCaster* owner, TypeOfSpell spellType)
                : actionPoints(actionPoints),  cost(cost), spellName(spellName),
                owner(owner), spellType(spellType) {
}

Spell::~Spell() {}

int Spell::getActionPoints() const {
    return this->actionPoints;
}

int Spell::getCost() const {
    return this->cost;
}

const char* Spell::getSpellName() const {
    return this->spellName;
}

TypeOfSpell Spell::getSpellType() const {
    return this->spellType;
}
