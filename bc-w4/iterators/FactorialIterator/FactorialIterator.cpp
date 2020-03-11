#include "FactorialIterator.hpp"

FactorialIterator::FactorialIterator(int member) : member(member), current(1), array({1}) {}

void FactorialIterator::next() {
    if ( over() ) {
        return;
    }
    array.insert(array.begin()+current, array[current-1] * current); 
    current += 1;
}

unsigned long long int FactorialIterator::value() { return array[current-1]; }

bool FactorialIterator::over() { return current >= member; }

void FactorialIterator::operator++() { next(); }

void FactorialIterator::operator++(int) { operator++(); }

unsigned long long int FactorialIterator::operator*() { return value(); }
