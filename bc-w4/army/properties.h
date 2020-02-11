#pragma once
#ifndef PROPERTIES_H
#define PROPERTIES_H

enum class Hp {
    Soldier = 100,
    LightSoldier = 51,
    Rogue = 80,
    Berserker = 120,
    Vampire = 70,
    Werewolf = 50,
    Wizard = 60,
    Healer = 40,
    Priest = 80,
    Warlock = 90,
    Necromancer = 90
};

enum class Dmg {
    Soldier = 10,
    LightSoldier = 5,
    Rogue = 15,
    Berserker = 20,
    Vampire = 20,
    Werewolf = 10,
    Wizard = 10,
    Healer = 8,
    Priest = 8,
    Warlock = 11,
    Necromancer = 12
};

enum class Mana {
    Wizard = 90,
    Healer = 100,
    Priest = 120,
    Warlock = 80,
    Necromancer = 100
};

#endif //PROPERTIES_H
