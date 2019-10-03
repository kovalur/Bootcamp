#include <iostream>
#include "Unit.h"

int main() {
    Unit barbarian("Barbarian", 50, 20);
    Unit knight("Knight", 45, 25);
    
    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;
    
    barbarian.attack(knight);
    knight.attack(barbarian);
    barbarian.attack(knight);

    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;

    knight.addHitPoints(46);
    barbarian.addHitPoints(51);
    knight.attack(barbarian);
    
    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;
    
    return 0;
}
