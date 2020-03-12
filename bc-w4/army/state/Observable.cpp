#include "Observable.h"

Observable::Observable(Unit* owner) : owner(owner) {}

Observable::~Observable() {}

const Unit* Observable::getOwner() const {
    return this->owner;
}
