#include "MyComplex.h"
#include "cmath"

MyComplex::MyComplex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

MyComplex::~MyComplex() = default;

MyComplex MyComplex::operator+(const MyComplex &other) const {
    return {this->real + other.real, this->imaginary + other.imaginary};
}

MyComplex MyComplex::operator-(const MyComplex &other) const {
    return {this->real - other.real, this->imaginary - other.imaginary};
}

bool MyComplex::operator==(const MyComplex &other) const {
    return this->real == other.real && this->imaginary == other.imaginary;
}

double MyComplex::abs() const {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}