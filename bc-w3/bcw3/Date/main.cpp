#include <ostream>
#include <string>
#include "Date.h"

int main() {
    try {
        Date date(29, 02, 2000);
        
        std::cout << date << std::endl;
    } catch (InvalidDate e) {
        std::cout << e.text << std::endl;
    }

    return 0;
}
