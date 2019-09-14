#include <iostream>
#include "Complex.h"

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::~Complex() {}

double Complex::getReal() const {
    return this->real;
}

double Complex::getImaginary() const {
    return this->imaginary;
}

bool Complex::operator==(const Complex& other) const {
    return this->real == other.real && this->imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

void Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imaginary += other.imaginary;
}

void Complex::operator-=(const Complex& other) {
    this->real -= other.real;
    this->imaginary -= other.imaginary;
}

Complex Complex::operator+(const Complex& other) const {
    Complex sumOfComplexes;
    
    sumOfComplexes.real = this->real + other.real;
    sumOfComplexes.imaginary = this->imaginary + other.imaginary;
    return sumOfComplexes;
}

Complex Complex::operator-(const Complex& other) const {
    Complex diffOfComplexes;
    
    diffOfComplexes.real = this->real - other.real;
    diffOfComplexes.imaginary = this->imaginary - other.imaginary;
    return diffOfComplexes;
}

Complex Complex::operator*(const Complex& other) const {
    Complex multiplyOfComplexes;
    
    multiplyOfComplexes.real = this->real * other.real - this->imaginary * other.imaginary;
    multiplyOfComplexes.imaginary = this->real * other.imaginary + this->imaginary * other.real;
    return multiplyOfComplexes;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if ( complex.getImaginary() == 0 ) {
        return out << complex.getReal();
    } else if ( complex.getReal() == 0 ) {
        return out << complex.getImaginary() << 'i';
    }
    out << complex.getReal();
    out << std::showpos;
    out << complex.getImaginary() << 'i';
    out << std::noshowpos;
    return out; 
}
