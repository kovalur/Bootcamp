#include "GeomProgrIterator.hpp"

GeomProgrIterator::GeomProgrIterator(int start, int step, int count) : step(step), count(count),
                                                                        current(start), counter(1) {}

void GeomProgrIterator::next() {
    if ( over() ) {
        return;
    }
    current *= step;
    counter += 1;
}

int GeomProgrIterator::value() { return current; }

bool GeomProgrIterator::over() { return counter >= count; }

void GeomProgrIterator::operator++() { next(); }

void GeomProgrIterator::operator++(int) { operator++(); }

int GeomProgrIterator::operator*() { value(); }
