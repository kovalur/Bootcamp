#include <iostream>
#include "Complex.h"

int main() {
    Complex a(-1.1, 2.2);
    Complex b(1.2, -2.1);
    Complex c;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    c = a;
    a += b; 
    
    if ( a != b ) {
        std::cout << a << " is not equal to " << b << std::endl;
    } else {
        std::cout << a << " is equal to " << b << std::endl;
    }
    
    b += c;
    
    a -= c;
    b -= a;
    c = a + b;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    c = a * b;
    
    std::cout << "c: " << c << std::endl;
    
    return 0;
}
