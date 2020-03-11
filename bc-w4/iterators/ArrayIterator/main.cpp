#include "ArrayIterator.hpp"

#include <iostream>


int main() {
    int array[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    ArrayIterator seq(array, 10);
    
    for ( int i = 1; !seq.over() && i < 10; seq++, i++ ) {
        std::cout << *seq << ' ';
    }
    seq.next();
    std::cout << seq.value() << std::endl;
    
    return 0;
}
