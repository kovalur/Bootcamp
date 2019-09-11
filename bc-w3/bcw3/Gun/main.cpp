#include <ostream>
#include "Gun.h"

int main() {
    Gun beretta;
    Gun colt("Colt", 2);
    
    std::cout << beretta << std::endl;
    std::cout << colt << std::endl;
    
    colt.reload();
    colt.prepare();
    
    colt.shoot();
    colt.shoot();
    
    std::cout << beretta << std::endl;
    std::cout << colt << std::endl;
    
    try {
        colt.shoot();
    } catch (OutOfRounds e) {
        std::cout << "No bullets left." << std::endl;
    }
    
    try {
        beretta.shoot();
    } catch (NotReady e) {
        std::cout << "Gun is not prepared for shooting." << std::endl;
    }
    
    return 0;
}
