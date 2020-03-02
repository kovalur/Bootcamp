#include "Passport.h"

int main() {
    try {
        Passport *p1 = new Passport("Bruno", "Jorge", 1994, 2, 7);
        
        std::cout << "##########################" << std::endl;
        std::cout << *p1 << std::endl;
        
        Passport::changePassportSeries("ZZ");
        Passport::changePassportNumber(999999);
        
        Passport *p2 = new Passport("Felicia", "Lagrange", 1955, 1, 2);
        // Passport *p3 = new Passport("John", "Walenso", 1945, 1, 2);
        
        std::cout << "##########################" << std::endl;
        std::cout << *p2 << std::endl;
        // std::cout << "##########################" << std::endl;
        // std::cout << *p3 << std::endl;
    } catch (Exception* e) {
        std::cout << e->text << std::endl;
    }

    std::cout << Passport::currentPasswordSeries() << std::endl;
    std::cout << Passport::currentPasswordNumber() << std::endl;

    return 0;
}
