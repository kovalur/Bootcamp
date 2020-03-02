#include "Passport.h"

Passport::Passport(std::string firstName, std::string lastName,
                   int yearOfBirth, int monthOfBirth, int dayOfBirth)
                   : firstName(firstName), lastName(lastName) {
    this->validate(dayOfBirth, monthOfBirth, yearOfBirth);
    this->dateOfBirthParams.insert(std::pair<std::string,int>("year", yearOfBirth));
    this->dateOfBirthParams.insert(std::pair<std::string,int>("month", monthOfBirth));
    this->dateOfBirthParams.insert(std::pair<std::string,int>("day", dayOfBirth));
    this->setDateOfBirth();
    this->setPassportId();
}

Passport::~Passport() {}

const std::string& Passport::getFirstName() const {
    return this->firstName;
}

const std::string& Passport::getLastName() const {
    return this->lastName;
}

const std::string& Passport::getDateOfBirth() const {
    return this->dateOfBirth;
}

const std::string& Passport::getPassportId() const {
    return this->passportId;
}

std::string Passport::currentPasswordSeries() {
    return std::string(1, passportSeries[0]) + std::string(1, passportSeries[1]);
}

unsigned int Passport::currentPasswordNumber() {
    return passportNumber == PN_H + 1 ? passportNumber - 1 : passportNumber;
}

void Passport::setDateOfBirth() {
    std::string year = std::to_string(this->dateOfBirthParams["year"]);
    std::string month = std::to_string(this->dateOfBirthParams["month"]);
    std::string day = std::to_string(this->dateOfBirthParams["day"]);
    this->dateOfBirth = month + '/' + day + '/' + year;
}

void Passport::setPassportId() {
    if ( passportNumber > PN_H ) {
        this->adjustIdParams(); 
    }
    std::string buffer = std::to_string(passportNumber);
    this->passportId = std::string(1, passportSeries[0]) + std::string(1, passportSeries[1])
                        + std::string(6-buffer.length(), '0') + buffer;
    passportNumber += 1;
}

void Passport::changePassportSeries(const std::string& series) {
    if ( series.length() > 2 ) {
        throw new InvalidPassportSeries();
    }
    
    char a = series[0];
    char b = series[1];
    if ( a < PS_L || a > PS_H || b < PS_L || b > PS_H ) {
        throw new InvalidPassportSeries();
    }
    passportSeries[0] = a;
    passportSeries[1] = b;
    passportNumber = PN_L;
}

void Passport::changePassportNumber(int number) {
    if ( number > PN_H || number <= 0 ) {
        throw new InvalidPassportNumber();
    }
    passportNumber = number;
}

void Passport::validate(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string text = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year) + " is invalid date.";
    
    if ( month > 0 && month <= 12 && year > 0 && day > 0 ) {
        if ( !(year % 400 || year % 4) && month == 2 ) {
            if ( day <= 29 ) {
                return;
            }
        }
        if ( day <= daysInMonth[month-1] ) {
            return;
        }
    }
    throw new InvalidDate(text);
}

void Passport::adjustIdParams() {
    if ( passportSeries[0] == PS_H && passportSeries[1] == PS_H ) {
        passportNumber = PN_H;
        throw new PassportIdLimit();
    }
    if ( passportSeries[1] < PS_H ) {
        passportSeries[1] = passportSeries[1] + 1;
        passportNumber = PN_L;
        return;
    }
    if ( passportSeries[0] < PS_H ) {
        passportSeries[0] = passportSeries[0] + 1;
        passportSeries[1] = 'A';
        passportNumber = PN_L;
    }
}

std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    out << passport.getFirstName() << std::string(1, ' ') << passport.getLastName() << std::endl;
    out << passport.getDateOfBirth() << std::endl;
    out << passport.getPassportId();
    
    return out;
}

char Passport::passportSeries[2] = {PS_L, PS_L};
unsigned int Passport::passportNumber = PN_L;
