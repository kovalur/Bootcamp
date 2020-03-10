#pragma once
#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "Vampire.h"
#include "../ability/DefaultAbility.h"

#include <string>

enum werewolfState { werewolf, wolf };

class Werewolf : public Unit {
    private:
        werewolfState currentState;
        int wolfExtraHp;
        int wolfExtraDmg;
    public:
        Werewolf(const char* title, int hitPoints, int damage);
        virtual ~Werewolf();
        
        void takeMagicDamage(int dmg) override;
        void transform();
        Werewolf* makeWerewolf(const Unit* victim);
};

#endif // WEREWOLF_H
