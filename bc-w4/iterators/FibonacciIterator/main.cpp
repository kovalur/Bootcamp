#include "FibonacciIterator.hpp"

#include <iostream>


int main() {
    FibonacciIterator seq(-20);
    
    for ( int i = 1; !seq.over() && i <= 20; seq++, i++ ) {
        std::cout << *seq << ' ';
    }
    std::cout << seq.value() << std::endl;
    
    return 0;
}
