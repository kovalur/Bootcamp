#include "FibonacciIterator.hpp"

FibonacciIterator::FibonacciIterator(int member) : member(member), counter(0) {}

long long int FibonacciIterator::fibonacci(int n) {
    if ( n == 0 ) {
        return 0;
    }
    if ( n == 1 || n == -1 ) {
        return 1;
    }
    if ( n < 0 ) {
        return fibonacci(n+2) - fibonacci(n+1);
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void FibonacciIterator::next() {
    if ( over() ) {
        return;
    }
    member < 0 ? counter -= 1 : counter += 1;
}

long long int FibonacciIterator::value() { return fibonacci(counter); }

bool FibonacciIterator::over() { return member < 0 ? overNegative() : overPositive(); }

bool FibonacciIterator::overNegative() { return counter <= member; }

bool FibonacciIterator::overPositive() { return counter >= member; }

void FibonacciIterator::operator++() { next(); }

void FibonacciIterator::operator++(int) { operator++(); }

long long int FibonacciIterator::operator*() { return value(); }
