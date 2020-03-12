#pragma once
#ifndef GEOM_PROGR_ITERATOR_H
#define GEOM_PROGR_ITERATOR_H

class GeomProgrIterator {
    private:
        int step;
        int count;
        int current;
        int counter;
    public:
        GeomProgrIterator(int start, int step, int count);
        
        void next();
        int value();
        bool over();
        void operator++();
        void operator++(int);
        int operator*();  
};

#endif // GEOM_PROGR_ITERATOR_H
