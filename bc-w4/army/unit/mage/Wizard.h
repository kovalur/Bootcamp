#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../../spell/SurgeOfLightning.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const char* title, int hitPoints, int damage, int mana);
        virtual ~Wizard();
        
        virtual void counterAttack(Unit* enemy);
};

#endif //WIZARD_H
