#include "Identifiable.h"

#include <iostream>

int main() {
    Identifiable* id1 = new Identifiable();
    Identifiable* id2 = new Identifiable();
    
    std::cout << "##########################" << std::endl;
    std::cout << "(1) => " << id1->getId() << std::endl;
    std::cout << "(2) => " << id2->getId() << std::endl;
    
    delete(id1);
    
    Identifiable* id3 = new Identifiable();
    Identifiable* id4 = new Identifiable();
    
    std::cout << "##########################" << std::endl;
    std::cout << "(3) => " << id3->getId() << std::endl;
    std::cout << "(4) => " << id4->getId() << std::endl;
    
    // std::random_device rd;
    // std::cout << "minimum: " << rd.min() << std::endl;
    // std::cout << "maximum: " << rd.max() << std::endl;
    
    return 0;
}
