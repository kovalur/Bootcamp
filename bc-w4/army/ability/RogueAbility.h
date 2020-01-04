#ifndef ROGUEABILITY_H
#define ROGUEABILITY_H

#include "Ability.h"

class RogueAbility : public Ability {
    public:
        RogueAbility(Unit* owner);
        virtual ~RogueAbility();
        
        virtual void attack(Unit* enemy);
};

#endif //ROGUEABILITY_H
