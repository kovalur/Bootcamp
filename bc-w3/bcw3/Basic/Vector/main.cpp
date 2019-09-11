#include <iostream>
#include <cmath>
#include "Vector.h"

int main() {
    Vector a(1, 5);
    Vector b(5, 1);
    Vector c;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    std::cout << "Length of a: " << a.len() << std::endl; 
    
    c = a;
    a += b; 
    
    if ( a != b ) {
        std::cout << a << " is not equal to " << b << std::endl;
    } else if ( a == b ) {
        std::cout << a << " is equal to " << b << std::endl;
    }
    
    b += c;
    
    a -= c;
    b -= a;
    c = a + b;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    c = a - b;
    
    std::cout << "c: " << c << std::endl;
    
    return 0;
}
