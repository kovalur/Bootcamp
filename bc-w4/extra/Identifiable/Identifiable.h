#pragma once
#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

#include <random>

class Identifiable {
    private:
        static std::random_device rd;
        unsigned int id;
    public:
        Identifiable();
        virtual ~Identifiable();
        
        const unsigned int& getId() const;
};

#endif //IDENTIFIABLE_H
