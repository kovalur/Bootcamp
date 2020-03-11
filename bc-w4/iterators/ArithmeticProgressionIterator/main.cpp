#include "ArithmProgrIterator.hpp"

#include <iostream>


int main() {
    ArithmProgrIterator seq(1, 2, 10);
    
    for ( int i = 1; !seq.over() && i < 10; seq++, i++ ) {
        std::cout << *seq << ' ';
    }
    std::cout << seq.value() << std::endl;
    
    return 0;
}
