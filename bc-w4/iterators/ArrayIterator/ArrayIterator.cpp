#include "ArrayIterator.hpp"


ArrayIterator::ArrayIterator(int array[], int size) : array(array), limit(size), current(0) {}

void ArrayIterator::next() {
    if ( over() ) {
        return;
    }
    current += 1;
}

int ArrayIterator::value() {
    if ( over() ) {
        return array[current-1];
    }
    return array[current];
}

bool ArrayIterator::over() { return current == limit; }

void ArrayIterator::operator++() { next(); }

void ArrayIterator::operator++(int) { operator++(); }

int ArrayIterator::operator*() { return value(); }
