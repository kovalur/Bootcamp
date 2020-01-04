#include "HealFriend.h"

HealFriend::HealFriend(int actionPoints, int cost)
    : Spell(actionPoints, cost) {
    std::cout << "HealFriend object initialized." << std::endl;
}

HealFriend::~HealFriend() {
    std::cout << "HealFriend object destroyed." << std::endl;
}

void HealFriend::action(Unit* target) {
    target->addHitPoints(this->actionPoints);
}
