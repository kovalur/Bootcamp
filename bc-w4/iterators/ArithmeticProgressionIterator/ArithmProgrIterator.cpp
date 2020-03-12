#include "ArithmProgrIterator.hpp"

ArithmProgrIterator::ArithmProgrIterator(int start, int step, int count) : step(step), count(count),
                                                                            current(start), counter(1) {}

void ArithmProgrIterator::next() {
    if ( over() ) {
        return;
    }
    current += step;
    counter += 1;
}

int ArithmProgrIterator::value() { return current; }

bool ArithmProgrIterator::over() { return counter >= count; }

void ArithmProgrIterator::operator++() { next(); }

void ArithmProgrIterator::operator++(int) { operator++(); }

int ArithmProgrIterator::operator*() { return value(); }
