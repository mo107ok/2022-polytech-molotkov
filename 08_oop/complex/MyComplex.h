#pragma once

class MyComplex {
public:
    MyComplex(double real = 0, double imaginary = 0);
    ~MyComplex();

    MyComplex operator+(const MyComplex &other) const;
    MyComplex operator-(const MyComplex &other) const;
    bool operator==(const MyComplex &other) const;
    double abs() const;
private:
    double real;
    double imaginary;
};