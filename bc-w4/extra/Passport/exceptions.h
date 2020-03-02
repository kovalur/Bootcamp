#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

class Exception {
    public:
        std::string text;
        
        Exception(const std::string& text) : text(text) {}
        virtual ~Exception() {}
};

class InvalidDate : public Exception {
    public:
        InvalidDate(const std::string& text) : Exception(text) {}
        virtual ~InvalidDate() {}
};

class PassportIdLimit : public Exception {
    public:
        PassportIdLimit(const std::string &text = "Sorry, Passport Id limit was reached.") : Exception(text) {}
        virtual ~PassportIdLimit() {}
};

class InvalidPassportSeries : public Exception {
    public:
        InvalidPassportSeries(const std::string &text = "Invalid Passport Series.") : Exception(text) {}
        virtual ~InvalidPassportSeries() {}
};

class InvalidPassportNumber : public Exception {
    public:
        InvalidPassportNumber(const std::string &text = "Invalid Passport Number.") : Exception(text) {}
        virtual ~InvalidPassportNumber() {}
};

#endif //EXCEPTIONS_H
