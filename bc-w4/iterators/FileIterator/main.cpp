#include "FileIterator.hpp"

#include <iostream>


int main() {
    FileIterator fIt("test.txt");
    
    for ( ; !fIt.over(); fIt++ ) {
        std::cout << *fIt << std::endl;
    }
    
    return 0;
}
