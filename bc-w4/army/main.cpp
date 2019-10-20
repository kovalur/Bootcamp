#include <iostream>
#include "units/SpellCaster.h"
#include "units/Unit.h"

int main() {
    Unit unit(25, 120, "Ordinary Slodier");
    SpellCaster spellCaster(22, 10, 80, "Spelly", 100);
    
    std::cout << unit << std::endl;
    std::cout << spellCaster << std::endl;
    
    unit.attack(spellCaster);
    spellCaster.attack(unit);
    
    std::cout << unit << std::endl;
    std::cout << spellCaster << std::endl;

    return 0;
}
