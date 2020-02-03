#include "Observable.h"

Observable::Observable(Unit* owner) : owner(owner) {
    std::cout << "Observable object initialized." << std::endl;
}

Observable::~Observable() {
    std::cout << "Observable object destroyed." << std::endl;
}

const Unit* Observable::getOwner() const {
    return this->owner;
}
