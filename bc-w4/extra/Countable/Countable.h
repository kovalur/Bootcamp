#pragma once
#ifndef COUNTABLE_H
#define COUNTABLE_H

class Countable {
    private:
        static unsigned int count;
    public:
        Countable();
        virtual ~Countable();
        
        static const unsigned int& getCount();
};

#endif //COUNTABLE_H
