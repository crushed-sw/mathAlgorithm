#ifndef _MATH_ALGORITHM_REALPOLY_HPP_
#define _MATH_ALGORITHM_REALPOLY_HPP_

#include <iostream>
#include <cmath>

class Poly {
private:
    int N;
    double* p;

public:
    Poly(int nn=0, double* pp=nullptr);

    void input();
    double poly_value(double);
    void poly_mul(Poly&, Poly&);
    void poly_div(Poly&, Poly&, Poly&);
};

#endif // _MATH_ALGORITHM_REALPOLY_HPP_
