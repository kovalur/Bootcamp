#include "PrimeNumIterator.hpp"

#include <iostream>


int main() {
    PrimeNumIterator seq(30);
    
    for ( int i = 1; !seq.over() && i < 30; seq++, i++ ) {
        std::cout << *seq << ' ';
    }
    seq.next();
    std::cout << seq.value() << std::endl;
    
    return 0;
}
