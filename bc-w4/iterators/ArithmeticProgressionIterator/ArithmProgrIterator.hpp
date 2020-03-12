#pragma once
#ifndef ARITHM_PROGR_ITERATOR_H
#define ARITHM_PROGR_ITERATOR_H

class ArithmProgrIterator {
    private:
        int step;
        int count;
        int current;
        int counter;
    public:
        ArithmProgrIterator(int start, int step, int count);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();
};

#endif // ARITHM_PROGR_ITERATOR_H
