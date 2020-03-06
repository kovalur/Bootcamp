#include <iostream>
#include "Mohican.h"

int main() {
    Mohican* m1 = new Mohican("Joie");
    Mohican* m2 = new Mohican("Luise");
    Mohican* m3 = new Mohican("Brandon");
    Mohican* m4 = new Mohican("Karl");
    
    std::cout << "##########################" << std::endl;
    std::cout << "(1) => " << m1->getName() << std::endl;
    std::cout << "(2) => " << m2->getName() << std::endl;
    std::cout << "(3) => " << m3->getName() << std::endl;
    std::cout << "(4) => " << m4->getName() << std::endl;
    std::cout << Mohican::getLastOfMohicans() << std::endl;
    
    delete(m1);
    delete(m4);
    delete(m3);
    
    std::cout << "##########################" << std::endl;
    std::cout << Mohican::getLastOfMohicans() << std::endl;
    
    Mohican* m5 = new Mohican("Patrik");
    
    std::cout << "##########################" << std::endl;
    std::cout << "(2) => " << m2->getName() << std::endl;
    std::cout << "(5) => " << m5->getName() << std::endl;
    std::cout << Mohican::getLastOfMohicans() << std::endl;
    
    delete(m2);
    delete(m5);
    
    return 0;
}
