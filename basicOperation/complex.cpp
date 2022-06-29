#include "../include/complex.hpp"

Complex::Complex(double real, double imag) : R(real), I(imag) {}

// 复数输出
void Complex::ptr() const {
    std::cout << R;
    if(I >= 0)
        std::cout << "+";
    std::cout << I << "j";
    return;
}

// 复数模
double Complex::cfabs() const {
    return std::sqrt(R * R + I * I);
}

// 复数幅角
double Complex::angle() const {
    return std::atan2(I, R);
}

// 复数加法
Complex Complex::operator+(const Complex& c2) const {
    Complex c(R + c2.R, I + c2.I);
    return c;
}

// 复数减法
Complex Complex::operator-(const Complex& c2) const {
    Complex c(R - c2.R, I - c2.I);
    return c;
}

// 复数乘法
Complex Complex::operator*(const Complex& c2) const {
    Complex c;
    double p, q, s;

    p = R * c2.R;
    q = I * c2.I;
    s = (R + I) * (c2.R + c2.I);

    c.R = p - q;
    c.I = s - p - q;
    return c;
}

// 复数除法
Complex Complex::operator/(const Complex& c2) const {
    Complex c;
    double p, q, s, w;

    p = R * c2.R;
    q = -I * c2.I;
    s = (R + I) * (c2.R - c2.I);
    w = c2.R * c2.R + c2.I * c2.I;

    if(w + 1.0 != 1.0) {
        c.R = (p - q) / w;
        c.I = (s - p - q) / w;
    } else {
        c.R = 1e+300;
        c.I = 1e+300;
    }

    return c;
}

// 复数乘幂
Complex Complex::cpower(int n) const {
    Complex c;
    double r, q;

    q = std::atan2(I, R);
    r = std::sqrt(R * R + I * I);

    if(r + 1.0 != 1.0) {
        r = n * std::log(r);
        r = std::exp(r);
    }

    c.R = r * std::cos(n * q);
    c.I = r * std::sin(n * q);

    return c;
}

// 复数的n次方根
void Complex::croot(int n, Complex* p) {
    Complex c;
    int k;
    double r, q, t;

    if(n < 1) 
        return;

    q = std::atan2(I, R);
    r = std::sqrt(R * R + I * I);

    if(r + 1.0 != 1.0) {
        r = (1.0 / n) * std::log(r);
        r = std::exp(r);
    }

    for(k = 0; k != n; ++k) {
        t = (2.0 * k * 3.1415926535 + q) / n;

        c.R = r * std::cos(t);
        c.I = r * std::sin(t);

        p[k] = c;
    }
}

// 复数指数
Complex Complex::cexp() const {
    Complex c;
    double q;

    q = std::exp(R);
    c.R = q * std::cos(I);
    c.I = q * std::sin(I);

    return c;
}

// 复数对数
Complex Complex::clog() const {
    Complex c;
    double p;

    p = R * R + I * I;
    p = log(std::sqrt(p));

    c.R = p;
    c.I = std::atan2(I, R);
    return c;
}

// 复数正弦
Complex Complex::csin() const {
    Complex c;
    double p, q;

    p = std::exp(I);
    q = std::exp(-I);

    c.R = std::sin(R) * (p + q) / 2;
    c.I = std::cos(R) * (p - q) / 2;

    return c;
}

// 复数余弦
Complex Complex::ccos() const {
    Complex c;
    double p, q;

    p = std::exp(I);
    q = std::exp(-I);

    c.R = std::cos(R) * (p + q) / 2;
    c.I = -std::sin(R) * (p - q) / 2;

    return c;
}

std::ostream& operator<<(std::ostream& output, const Complex& c) {
    output << c.R;
    if(c.I >= 0)
        output << "+";
    output << c.I << "j";
    return output;
}

Complex cexp(const Complex& c) {
    return c.cexp();
}

Complex clog(const Complex& c) {
    return c.clog();
}

Complex csin(const Complex& c) {
    return c.csin();
}

Complex ccos(const Complex& c) {
    return c.ccos();
}
