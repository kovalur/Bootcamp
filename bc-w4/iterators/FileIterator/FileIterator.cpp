#include "FileIterator.hpp"

FileIterator::FileIterator(const char* filename) : file(filename) {                          
    std::getline(file, current);
}

FileIterator::~FileIterator() { file.close(); }

void FileIterator::next() {
    if ( over() ) {
        return;
    }
    current.clear();
    if ( current.empty() ) {
        if (file.is_open()) {
            std::getline(file, current);
        }
    }
}

const std::string& FileIterator::value() { return current; }

bool FileIterator::over() { return file.eof(); }

void FileIterator::operator++() { next(); }

void FileIterator::operator++(int) { operator++(); }

const std::string& FileIterator::operator*() { return value(); }
