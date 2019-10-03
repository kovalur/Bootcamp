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
    if ( this->inkAmount == 0 ) {
        throw OutOfInk();
    }
    
    if ( message.length() > this->inkAmount ) {
        paper.addContent(message.substr(0, this->inkAmount));
        this->inkAmount = 0;
        return;
    }
    paper.addContent(message);
    this->inkAmount -= message.length();
}

void Pen::refill() {
    inkAmount = inkCapacity;
}
