#pragma once
#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

class ArrayIterator {
    private:
        int limit;
        int* array;
        int current;
    public:
        ArrayIterator(int array[], int size);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();
};

#endif // ARRAY_ITERATOR_H
