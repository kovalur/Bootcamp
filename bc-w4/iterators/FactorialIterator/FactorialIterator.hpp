#pragma once
#ifndef FACTORIAL_ITERATOR_H
#define FACTORIAL_ITERATOR_H

#include <vector>

class FactorialIterator {
    private:
        int member;
        int current;
        std::vector<unsigned long long int> array;
    public:
        FactorialIterator(int member);
        
        void next();
        unsigned long long int value();
        bool over();
        void operator++();
        void operator++(int);
        unsigned long long int operator*();
};

#endif // FACTORIAL_ITERATOR_H
