#pragma once
#ifndef NATURAL_NUMBERS_ITERATOR_H
#define NATURAL_NUMBERS_ITERATOR_H

class NaturalNumbersIterator {
    private:
        int limit;
        int current;
    public:
        NaturalNumbersIterator(int limit);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();
};

#endif // NATURAL_NUMBERS_ITERATOR_H
