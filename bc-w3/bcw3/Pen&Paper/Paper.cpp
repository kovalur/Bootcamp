#include <iostream>
#include "Paper.h"

Paper::Paper(int maxSymbols) : maxSymbols(maxSymbols), symbols(0), content("") {}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return maxSymbols;
}

int Paper::getSymbols() const {
    return symbols;
}

void Paper::addContent(const std::string& message) {
    int spaceLeft = this->maxSymbols - this->symbols;
    std::string textToAdd = message.substr(0, spaceLeft);
    
    if ( spaceLeft == 0 ) {
        throw OutOfSpace();
    }
    
    this->content += textToAdd;
    this->symbols += textToAdd.length();
}

void Paper::show() const {
    std::cout << this->content << std::endl;
}
