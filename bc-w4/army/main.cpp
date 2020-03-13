#include "unit/Soldier.h"
#include "unit/Demon.h"
#include "unit/Rogue.h"
#include "unit/Berserker.h"
#include "unit/Vampire.h"
#include "unit/Werewolf.h"
#include "unit/mage/Wizard.h"
#include "unit/mage/Healer.h"
#include "unit/mage/Priest.h"
#include "unit/mage/Warlock.h"
#include "unit/mage/Necromancer.h"
#include "properties.h"
#include "exceptions.h"

#include <iostream>


int main() {
    Soldier* soldier = new Soldier("Soldier", int(Hp::Soldier), int(Dmg::Soldier));
    Unit* soldier2 = new Soldier("Soldier2", int(Hp::Soldier), int(Dmg::Soldier));
    Rogue* rogue = new Rogue("Rogue", int(Hp::Rogue), int(Dmg::Rogue));
    Unit* rogue2 = new Rogue("Rogue2", int(Hp::Rogue), int(Dmg::Rogue));
    Berserker* berserker = new Berserker("Berserker", int(Hp::Berserker), int(Dmg::Berserker));
    Vampire* vampire = new Vampire("Vampire", int(Hp::Vampire), int(Dmg::Vampire), 5);
    Unit* vampire2 = new Vampire("Vampire2", int(Hp::Vampire), int(Dmg::Vampire), 5);
    Werewolf* werewolf = new Werewolf("Werewolf", int(Hp::Werewolf), int(Dmg::Werewolf));
    Unit* werewolf2 = new Werewolf("Werewolf2", int(Hp::Werewolf), int(Dmg::Werewolf));
    Wizard* wizard = new Wizard("Wizard", int(Hp::Wizard), int(Dmg::Wizard), int(Mana::Wizard));
    Healer* healer = new Healer("Healer", int(Hp::Healer), int(Dmg::Healer), int(Mana::Healer));
    Priest* priest = new Priest("Priest", int(Hp::Priest), int(Dmg::Priest), int(Mana::Priest));
    Warlock* warlock = new Warlock("Warlock", int(Hp::Warlock), int(Dmg::Warlock), int(Mana::Warlock));
    Necromancer* necromancer = new Necromancer("Necromancer", int(Hp::Necromancer), int(Dmg::Necromancer), int(Mana::Necromancer));
    
    std::cout << "**************START INFO**************" << std::endl;
    std::cout << *soldier << std::endl;
    std::cout << *rogue << std::endl;
    std::cout << *(dynamic_cast<Soldier*>(soldier2)) << std::endl;
    std::cout << *(dynamic_cast<Rogue*>(rogue2)) << std::endl;
    std::cout << *berserker << std::endl;
    std::cout << *vampire << std::endl;
    std::cout << *werewolf << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << *healer << std::endl;
    std::cout << *priest << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *necromancer << std::endl;
    
    std::cout << "**************ACTION : soldier->attack(healer)**************" << std::endl;
    soldier->attack(healer);
    
    std::cout << *soldier << std::endl;
    std::cout << *healer << std::endl;
    
    std::cout << "**************ACTION(Healing) : healer->cast(soldier)**************" << std::endl;
    healer->cast(soldier);
    
    std::cout << *soldier << std::endl;
    std::cout << *healer << std::endl;
    
    std::cout << "**************ACTION(Attacking) : healer->cast(soldier)**************" << std::endl;
    healer->changeSpell("SurgeOfLightning");
    
    healer->cast(soldier);
    
    std::cout << *soldier << std::endl;
    std::cout << *healer << std::endl;
    
    std::cout << "**************ACTION : rogue->attack(wizard)**************" << std::endl;
    rogue->attack(wizard);
    
    std::cout << *rogue << std::endl;
    std::cout << *wizard << std::endl;
    
    std::cout << "**************ACTION : berserker->attack(warlock)**************" << std::endl;
    try {
        berserker->attack(warlock);
    } catch (Exception &e) {
        std::cout << e.text << std::endl;
    }
    
    std::cout << *berserker << std::endl;
    std::cout << *warlock << std::endl;
    
    std::cout << "**************ACTION(Attacking) : warlock->cast(berserker)**************" << std::endl;
    try {
        warlock->cast(berserker);
    } catch (Exception &e) {
        std::cout << e.text << std::endl;
    }
    
    std::cout << *berserker << std::endl;
    std::cout << *warlock << std::endl;
    
    std::cout << "**************ACTION : demons[1]->attack(berserker)**************" << std::endl;
    int numOfDemons = 3;
    Demon* demons[numOfDemons];
    
    warlock->callDemons(numOfDemons, demons);
    
    demons[1]->attack(berserker);
    
    std::cout << *berserker << std::endl;
    for ( int i = 0; i < numOfDemons; i++ ) {
        std::cout << *(demons[i]) << std::endl;
    }
    
    std::cout << "**************ACTION : vampire->attack(priest)**************" << std::endl;
    vampire->attack(priest);
    
    std::cout << *vampire << std::endl;
    std::cout << *priest << std::endl;
    
    std::cout << "**************ACTION : priest->attack(vampire)**************" << std::endl;
    priest->attack(vampire);
    
    std::cout << *vampire << std::endl;
    std::cout << *priest << std::endl;
    
    std::cout << "**************ACTION(Attacking) : priest->cast(vampire)**************" << std::endl;
    priest->changeSpell("SurgeOfLightning");
    
    priest->cast(vampire);
    
    std::cout << *vampire << std::endl;
    std::cout << *priest << std::endl;
    
    std::cout << "**************ACTION(wolf) : werewolf->transform()**************" << std::endl;
    werewolf->transform();
    
    std::cout << *werewolf << std::endl;
    
    std::cout << "**************ACTION(werewolf) : werewolf->transform()**************" << std::endl;
    werewolf->transform();
    
    std::cout << *werewolf << std::endl;
    
    std::cout << "**************ACTION(wolf, Attacking) : werewolf->transform() && werewolf->attack(priest)**************" << std::endl;
    werewolf->transform();
    
    werewolf->attack(priest);
    
    std::cout << *werewolf << std::endl;
    std::cout << *priest << std::endl;
    
    std::cout << "**************ACTION(wolf, Healing) : werewolf->transform() && priest->attack(werewolf) && priest->cast(werewolf)**************" << std::endl;
    
    priest->changeSpell("HealFriend");
    
    werewolf->transform();
    
    priest->attack(werewolf);
    
    priest->cast(werewolf); 
    
    std::cout << *werewolf << std::endl;
    std::cout << *priest << std::endl;
    
    std::cout << "**************ACTION : vampire->makeVampire(werewolf2)**************" << std::endl;
    try {
        werewolf2 = vampire->makeVampire(werewolf2);
    } catch (Exception &e) {
        std::cout << e.text << std::endl;
    }
    
    std::cout << "**************ACTION : werewolf->makeWerewolf(vampire2)**************" << std::endl;
    try {
        vampire2 = werewolf->makeWerewolf(vampire2);
    } catch (Exception &e) {
        std::cout << e.text << std::endl;
    }
    
    std::cout << "**************ACTION : vampire->makeVampire(soldier2)**************" << std::endl;
    soldier2 = vampire->makeVampire(soldier2);
    
    std::cout << *soldier2 << std::endl;
    
    std::cout << "**************ACTION : werewolf->makeWerewolf(rogue2)**************" << std::endl;
    rogue2 = werewolf->makeWerewolf(rogue2);
    
    std::cout << *rogue2 << std::endl;
    
    std::cout << "**************ACTION : necromancer->attack(werewolf)**************" << std::endl;
    for ( ; werewolf->getHitPoints() > 0; ) {
        necromancer->attack(werewolf);
    }
    
    std::cout << *necromancer << std::endl;
    std::cout << *werewolf << std::endl;
    
    std::cout << "**************END INFO**************" << std::endl;
    std::cout << *soldier << std::endl;
    std::cout << *rogue << std::endl;
    std::cout << *(dynamic_cast<Vampire*>(soldier2)) << std::endl;
    std::cout << *(dynamic_cast<Werewolf*>(rogue2)) << std::endl;
    std::cout << *berserker << std::endl;
    std::cout << *vampire << std::endl;
    std::cout << *werewolf << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << *healer << std::endl;
    std::cout << *priest << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *necromancer << std::endl;
    
    delete soldier;
    delete rogue;
    delete soldier2;
    delete rogue2;
    delete berserker;
    delete vampire;
    delete vampire2;
    delete werewolf;
    delete werewolf2;
    delete wizard;
    delete healer;
    delete priest;
    delete warlock;
    delete necromancer;
    
    return 0;
}
