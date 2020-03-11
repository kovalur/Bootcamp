#include <cmath>

#include <vector>

class FactorialIterator {
    private:
        int member;
        int current;
        std::vector<unsigned long long int> array;
        
        unsigned long long int factorial(int n);
    public:
        FactorialIterator(int member);
        
        void next();
        unsigned long long int value();
        bool over();
        void operator++();
        void operator++(int);
        unsigned long long int operator*();
};
