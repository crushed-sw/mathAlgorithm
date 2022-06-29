#ifndef _MATH_ALGORITHM_COMPLEX_HPP_
#define _MATH_ALGORITHM_COMPLEX_HPP_

#include <iostream>
#include <cmath>

class Complex {
    friend std::ostream& operator<<(std::ostream& output, const Complex& c);

private:
    double R;
    double I;

public:
    Complex(double real=0, double imag=0);


    void ptr() const;
    double cfabs() const;
    double angle() const;

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;

    Complex cpower(int) const;
    void croot(int, Complex*);
    Complex cexp() const;
    Complex clog() const;
    Complex csin() const;
    Complex ccos() const;
};

Complex cexp(const Complex&);
Complex clog(const Complex&);
Complex csin(const Complex&);
Complex ccos(const Complex&);

#endif // _MATH_ALGORITHM_COMPLEX_HPP_
