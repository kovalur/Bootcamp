#pragma once
#ifndef FIBONACCI_ITERATOR_H
#define FIBONACCI_ITERATOR_H

class FibonacciIterator {
    private:
        int member;
        int counter;
        
        long long int fibonacci(int n);
        bool overPositive();
        bool overNegative();
    public:
        FibonacciIterator(int member);
        
        void next();
        long long int value();
        bool over();
        void operator++();
        void operator++(int);
        long long int operator*();
};

#endif // FIBONACCI_ITERATOR_H
