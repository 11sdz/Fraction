/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(3,-4), b(-5,6);
    cout<<a.getNumerator()<<" "<<a.getNumerator()<<endl;
    Fraction d(7,9);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl;
    cout << "a-b" << a-b << endl;
    cout << "a/b" << a/b << endl;
    cout << "a*b" << a*b << endl;
    cout << "2.3*b" << 2.3*b << endl;
    cout << "a+2.421" << a+2.421 << endl;
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;
    Fraction aa{0,4};
    Fraction bb{0,-4};
    cout<<(aa==bb)<<endl;
    std::stringstream ss_zero_denominator("3 2");
    ss_zero_denominator.str("-3 -8 -2 3 4");
    Fraction fara;
    Fraction fara2;
    ss_zero_denominator>>fara>>fara2;
    cout<<fara<<" abc " <<fara2 <<endl;
    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;


}
