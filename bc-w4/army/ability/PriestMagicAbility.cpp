#include "PriestMagicAbility.h"

PriestMagicAbility::PriestMagicAbility(SpellCaster* owner, Spell* spell)
    : MagicAbility(owner, spell) {
    std::cout << "PriestMagicAbility object initialized." << std::endl;
}

void PriestMagicAbility::cast(Unit* target) {
    try {
        dynamic_cast<Undead&>(*target);
        
        if ( this->spell->getSpellType() == attacking ) {
            int actionPoints =  this->spell->getActionPoints();
            
            this->owner->ensureIsAlive();
            
            if ( this->owner->getMageType() != attacker ) {
                actionPoints /= 2;
            }
            target->takeMagicDamage(actionPoints);
        }
    } catch ( std::bad_cast& bc ) {}
    
    this->MagicAbility::cast(target);
}

void PriestMagicAbility::counterAttack(Unit* enemy) {
    int actionPoints = this->spell->getActionPoints() / 2;
    
    try {
        dynamic_cast<Undead&>(*enemy);
        
        actionPoints *= 2;
    } catch ( std::bad_cast& bc ) {}
    
    enemy->takeMagicDamage(actionPoints / 2);
    this->owner->spendMana(this->spell->getCost() / 2);
}
