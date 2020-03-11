#include "NaturalNumbersIterator.hpp"

#include <iostream>


int main() {
    NaturalNumbersIterator seq(10);
    
    for ( int i = 1; !seq.over() && i < 10 ; seq++, i++ ) {
        std::cout << *seq << ' ';
    }
    seq.next();
    std::cout << seq.value() << std::endl;
    
    return 0;
}
