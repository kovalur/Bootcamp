#include <iostream>
#include "Paper.h"
#include "Pen.h"

int main() {
    Paper paper(12);
    Pen pen(12);
    
    pen.write(paper, "Hello, world!");
    
    std::cout << "Paper max symbols: " << paper.getMaxSymbols() << std::endl;
    std::cout << "Paper symbols: " << paper.getSymbols() << std::endl;
    std::cout << "Pen ink amount: " << pen.getInkAmount() << std::endl;
    std::cout << "Pen ink capacity: " << pen.getInkCapacity()<< std::endl;
    
    try {
        pen.write(paper, "!");
    } catch (OutOfInk e) {
        std::cout << "Out of ink." << std::endl;
    }
    
    paper.show();
    
    pen.refill();
    std::cout << "Pen ink amount: " << pen.getInkAmount() << std::endl;
    
    try {
        pen.write(paper, "!");
    } catch (OutOfSpace e) {
        std::cout << "Out of space." << std::endl;
    }
    
    paper.show();
    
    return 0;
}
