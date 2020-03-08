#pragma once
#ifndef PASSPORT_H
#define PASSPORT_H

#include "exceptions.h"

#include <string>
#include <map>
#include <iostream>

#define PS_L 'A'
#define PS_H 'Z'
#define PN_L 1
#define PN_H 999999

class Passport {
    private:
        std::string firstName;
        std::string lastName;
        std::string dateOfBirth;
        std::map<std::string,int> dateOfBirthParams;
        static char passportSeries[2];
        static unsigned int passportNumber;
        std::string passportId;
        
        void setPassportId();
        void setDateOfBirth();
        
        void validateDate(int day, int month, int year);
        
        void adjustIdParams();
    public:
        Passport(std::string firstName, std::string lastName, int yearOfBirth, int monthOfBirth, int dayOfBirth);
        virtual ~Passport();
        
        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const std::string& getDateOfBirth() const;
        const std::string& getPassportId() const;
        
        static std::string currentPasswordSeries();
        static unsigned int currentPasswordNumber();
        static void changePassportSeries(const std::string& series);
        static void changePassportNumber(int number);
};

std::ostream& operator<<(std::ostream& out, const Passport& passport);

#endif //PASSPORT_H
