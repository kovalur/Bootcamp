#include "PrimeNumIterator.hpp"

PrimeNumIterator::PrimeNumIterator(int member) : member(member), counter(1), array({2}) {}

int nextPrime(int n) {
    bool isPrime = true;
    
    int i = n + 1;
    for ( ; isPrime; i++ ) {
        for ( int j = 2; j < i; j++ ) {
            if ( i % j == 0 ) {
                isPrime = false;
                break;
            }
        }
        if ( isPrime ) {
            break;
        }
        isPrime = !isPrime;
    }
    return i;
}

void PrimeNumIterator::next() {
    if ( over() ) {
        return;
    }
    array.insert(array.begin()+counter, nextPrime(array[counter-1]));
    counter += 1;
}

int PrimeNumIterator::value() { return array[counter-1]; }

bool PrimeNumIterator::over() { return counter >= member; }

void PrimeNumIterator::operator++() { next(); }

void PrimeNumIterator::operator++(int) { operator++(); }

int PrimeNumIterator::operator*() { return value(); }
