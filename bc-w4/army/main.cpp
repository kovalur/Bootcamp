#include <iostream>
#include "unit/Soldier.h"
#include "unit/Rogue.h"
#include "unit/mage/Wizard.h"

int main() {
    // Soldier* soldier = new Soldier("Soldier", 100, 10);
    // Rogue* rogue = new Rogue("Rogue", 80, 8);
    Wizard* wizard = new Wizard("Wizard", 70, 5, 55);
    Wizard* megaWizard = new Wizard("Mega Wizard", 140, 10, 110);
    
    // std::cout << *soldier << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *rogue << std::endl;
    // std::cout << "******************************" << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << *megaWizard << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "**" << std::endl;
    std::cout << "**" << std::endl;
    
    // rogue->attack(soldier);
    // std::cout << *soldier << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *rogue << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    // soldier->attack(rogue);
    // std::cout << *rogue << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *soldier << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    // wizard->attack(soldier);
    // std::cout << *soldier << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *wizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    // rogue->attack(wizard);
    // std::cout << *wizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *rogue << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    // wizard->cast(rogue);
    // std::cout << *rogue << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *wizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    // soldier->attack(wizard);
    // std::cout << *wizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *soldier << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    // megaWizard->attack(wizard);
    // std::cout << *wizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *megaWizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    // wizard->cast(megaWizard);
    // std::cout << *megaWizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << *wizard << std::endl;
    // std::cout << "******************************" << std::endl;
    // std::cout << "**" << std::endl;
    // std::cout << "**" << std::endl;
    
    wizard->attack(megaWizard);
    std::cout << *megaWizard << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "**" << std::endl;
    std::cout << "**" << std::endl;
    
    // delete(soldier);
    // delete(rogue);
    delete(wizard);
    delete(megaWizard);
    
    return 0;
}
