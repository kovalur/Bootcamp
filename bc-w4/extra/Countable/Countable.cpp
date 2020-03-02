#include "Countable.h"

Countable::Countable() {
    count += 1;
}

Countable::~Countable() {
    count -= 1;
}

const unsigned int& Countable::getCount() {
    return count;
}

unsigned int Countable::count = 0;
