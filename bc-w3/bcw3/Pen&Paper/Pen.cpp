#include <iostream>
#include "Pen.h"
#include "Paper.h"

Pen::Pen(int inkCapacity) : inkCapacity(inkCapacity), inkAmount(inkCapacity) {}

Pen::~Pen() {}

int Pen::getInkAmount() const {
    return inkAmount;
}

int Pen::getInkCapacity() const {
    return inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    std::string textToWrite = message.substr(0, this->inkAmount);
    int symbolsBefore = paper.getSymbols();
    
    if ( this->inkAmount == 0 ) {
        throw OutOfInk();
    }
    
    paper.addContent(textToWrite);
    this->inkAmount -= paper.getSymbols() - symbolsBefore;
}

void Pen::refill() {
    inkAmount = inkCapacity;
}
