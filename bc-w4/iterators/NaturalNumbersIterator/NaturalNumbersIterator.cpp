#include "NaturalNumbersIterator.hpp"

NaturalNumbersIterator::NaturalNumbersIterator(int limit) : limit(limit), current(1) {}

void NaturalNumbersIterator::next() {
    if ( over() ) {
        return;
    }
    current += 1;
}

int NaturalNumbersIterator::value() {
    return current;
}

bool NaturalNumbersIterator::over() { return current >= limit; }

void NaturalNumbersIterator::operator++() { next(); }

void NaturalNumbersIterator::operator++(int) { operator++(); }

int NaturalNumbersIterator::operator*() { return value(); }
