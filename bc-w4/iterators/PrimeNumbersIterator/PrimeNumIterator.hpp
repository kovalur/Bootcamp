#pragma once
#ifndef PRIME_NUM_ITERATOR_H
#define PRIME_NUM_ITERATOR_H

#include <vector>

class PrimeNumIterator {
    private:
        int member;
        int counter;
        
        std::vector<int> array;
    public:
        PrimeNumIterator(int member);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();
};

#endif // PRIME_NUM_ITERATOR_H
