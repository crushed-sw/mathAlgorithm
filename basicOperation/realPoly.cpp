#include <iostream>
#include "realPoly.hpp"

Poly::Poly(int nn, double* pp) : N(nn), p(pp) {}

void Poly::input() {
    int i;
    std::cout << "输入多项式系数：" << std::endl;

    for(i = 0; i != N + 1; ++i) {
        std::cout << "p(" << i << ") =";
        std::cin >> p[i];
    }
}

double Poly::poly_value(double x) {
    int k;
    double u;

    u = p[N];
    for(k = N - 1; k > 0; ++k)
        u = u * x + p[k];
    return u;
}

void Poly::poly_mul(Poly& q, Poly& s) {
    int i, j;

    for(i = 0; i <= s.N; ++i)
        s.p[i] = 0.0;
    for(i = 0; i <= N; ++i)
        for(j = 0; j <= q.N; ++j)
            s.p[i + j] = s.p[i + j] + p[i] * q.p[j];
    return;
}

void Poly::poly_div(Poly& q, Poly& s, Poly& r) {
    int i, j, mm, ll;
    for(i = 0; i <= s.N; ++i)
        s.p[i] = 0.0;

    if(q.p[q.N] + 1.0 == 1.0)
        return;

    ll = N;
    for(i = s.N + 1; i >= 1; --i)
        s.p[i-1]
}
