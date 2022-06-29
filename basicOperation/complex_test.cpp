#include <iostream>
#include "../include/complex.hpp"
using namespace std;

int main() {
    int i;
    double a, b;
    Complex c1, c2, c3, c, p[5];
    cin >> a >> b;
    c1 = Complex(a, b);
    cout << "c1 = " << c1 << endl;
    cin >> a >> b;
    c2 = Complex(a, b);
    cout << "c2 = " << c2 << endl;
    cin >> a >> b;
    c3 = Complex(a, b);
    cout << "c3 = " << c3 << endl;

    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;

    c = c3.cpower(-3);
    cout << "c3的-3次方 = " << c << endl;
    c3.croot(5, p);
    cout << "c3的5次方根为 :" << endl;
    for(int k = 0; k != 5; ++k) {
        cout << p[k] << endl;
    }

    cout << "cexp(c3) = " << c3.cexp() << endl;
    cout << "clog(c3) = " << c3.clog() << endl;
    cout << "csin(c3) = " << c3.csin() << endl;
    cout << "ccos(c3) = " << c3.ccos() << endl;
}
