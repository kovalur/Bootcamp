#pragma once
#ifndef FILE_ITERATOR_H
#define FILE_ITERATOR_H

#include <fstream>
#include <string>

class FileIterator {
    private:
        std::ifstream file;
        std::string current = "";
    public:
        FileIterator(const char* filename);
        virtual ~FileIterator();
        
        void next();
        const std::string& value();
        bool over();
        void operator++();
        void operator++(int);
        const std::string& operator*();
};

#endif // FILE_ITERATOR_H
