#include "Identifiable.h"

Identifiable::Identifiable() {
    this->id = (unsigned long long)rd();
}

Identifiable::~Identifiable() {}

const unsigned int& Identifiable::getId() const {
    return this->id;
}

std::random_device Identifiable::rd;
