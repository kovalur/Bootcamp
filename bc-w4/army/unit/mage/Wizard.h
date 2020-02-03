#pragma once
#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const char* title, int hitPoints, int damage, int mana);
        virtual ~Wizard();
        
        void counterAttack(Unit* enemy) override;
};

#endif //WIZARD_H
