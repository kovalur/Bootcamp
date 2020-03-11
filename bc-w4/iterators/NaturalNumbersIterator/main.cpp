#include "NaturalNumbersIterator.hpp"

#include <iostream>


int main() {
    NaturalNumbersIterator seq(10);
    
    for ( ; !seq.over() && *seq <= 9 ; seq++ ) {
        std::cout << *seq << ' ';
    }
    std::cout << seq.value() << std::endl;
    
    return 0;
}
