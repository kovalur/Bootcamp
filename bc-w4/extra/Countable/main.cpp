#include <iostream>
#include "Countable.h"

int main() {
    std::cout << "##########################" << std::endl;
    std::cout << "Total count: " << Countable::getCount() << std::endl;
    
    Countable* c1 = new Countable();
    Countable* c2 = new Countable();
    Countable* c3 = new Countable();
    
    std::cout << "##########################" << std::endl;
    std::cout << "Total count: " << Countable::getCount() << std::endl;

    delete(c1);
    delete(c3);
    
    std::cout << "##########################" << std::endl;
    std::cout << "Total count: " << Countable::getCount() << std::endl;

    return 0;
}
