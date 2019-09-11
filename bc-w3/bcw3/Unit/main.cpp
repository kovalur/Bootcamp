#include <iostream>
#include "Unit.h"

int main() {
    Unit barbarian("Barbarian", 50, 20);
    Unit knight("Knight", 45, 25);
    
    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;
    
    try {
        barbarian.attack(knight);
        knight.attack(barbarian);
        barbarian.attack(knight);
        knight.attack(barbarian);
    } catch (UnitIsDead e) {
        std::cout << "Unit is dead." << std::endl;
    }
    
    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;
    
    return 0;
}
