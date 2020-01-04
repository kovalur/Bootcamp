#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
    : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new MagicAbility(this, new SurgeOfLightning(30, 30, this));
        std::cout << "Wizard object initialized." << std::endl;
}

Wizard::~Wizard() {
    std::cout << "Wizard object destroyed." << std::endl;
}

void Wizard::counterAttack(Unit* enemy) {
    this->magicAbility->counterAttack(enemy);
}
