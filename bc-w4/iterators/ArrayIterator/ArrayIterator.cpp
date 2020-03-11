#include "ArrayIterator.hpp"

ArrayIterator::ArrayIterator(int array[], int size) : array(array), limit(size), current(1) {}

void ArrayIterator::next() {
    if ( over() ) {
        return;
    }
    current += 1;
}

int ArrayIterator::value() { return array[current-1]; }

bool ArrayIterator::over() { return current >= limit; }

void ArrayIterator::operator++() { next(); }

void ArrayIterator::operator++(int) { operator++(); }

int ArrayIterator::operator*() { return value(); }
