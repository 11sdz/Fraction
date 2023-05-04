//
// Created by mintsdz on 4/16/23.
//
#include <iostream>
#include <stdexcept>
#include <limits.h>
#include <sstream>
#include <math.h>
using namespace std;

#include "sources/Fraction.hpp"
#include "doctest.h"
using namespace ariel;
/**
 * testing constructor
 */
TEST_CASE("Constructor"){
    Fraction a(1,-3);
    CHECK((a.getNumerator() == -1));
    CHECK((a.getDenominator() == 3));
    Fraction b(22,44);
    CHECK((b.getNumerator() == 1));
    CHECK((b.getDenominator() == 2));
    Fraction c(1/3);
    CHECK((c.getNumerator() == 333));
    CHECK((c.getDenominator() == 1000));

}
/**
 * Cannot divide by 0 , denominator cannot be 0.
 */
TEST_CASE("denominator cannot be zero, cannot divide by zero"){
    CHECK_THROWS_AS_MESSAGE(Fraction(1,0),runtime_error,"Denominator cannot be Zero");
    Fraction a(2,1);
    Fraction b(0,1);
    CHECK_THROWS_AS_MESSAGE(a/b,runtime_error,"Cannot divide by Zero");
    CHECK_NOTHROW(Fraction(0));
}
/**
 * the Fraction of INT_MAX/1 (numerator/denominator) after increment should be equal to INT_MIN/1
 */
TEST_CASE("going over the limit of INT_MAX/MIN"){
    Fraction max(INT_MAX,1);
    Fraction min(INT_MIN,1);
    CHECK_THROWS(max++);
    CHECK_THROWS(min--);
    CHECK_NOTHROW(max--);
    CHECK_NOTHROW(min++);
}

/**
 * Testing Binary operators +,-,*,/
 */
TEST_CASE("Binary operators"){
    Fraction a(7,10);
    Fraction b(10,25);
    Fraction c(1,2);

    Fraction ans=a+b;
    CHECK(((ans.getNumerator() == 11) && (ans.getDenominator() == 10)));

    ans=a*c;
    CHECK(((ans.getNumerator() == 7) && (ans.getDenominator() == 20)));

    ans=a/c;
    CHECK(((ans.getNumerator() == 7) && (ans.getDenominator() == 5)));

    ans=a-c;
    CHECK(((ans.getNumerator() == 1) && (ans.getDenominator() == 5)));
}

TEST_CASE("Output method"){
    Fraction half(1,2);
    std::ostringstream out;
    out<<half;
    CHECK(((out.str())==("1/2")));
}
TEST_CASE("input"){
    std::stringstream str("0 4");
    Fraction a;
    str>>a;
    CHECK(((a.getNumerator()==0) && (a.getDenominator()==1)));
}
/**
 * only 3 numbers after the decimal point
 */
TEST_CASE("Floats"){
    float af=1/3;// 0.3333333333333...
    Fraction id(1,1);
    Fraction a=id*af;
    CHECK((a.getNumerator() == 333));
    CHECK((a.getDenominator() == 1000));
    af=M_PI; //Pi 3.1415926...
    a=af*id;
    CHECK((a.getNumerator() == 3141));
    CHECK((a.getDenominator() == 1000));
}

/**
 * testing Relational operators ==,!=,<=,<,>=,>
 */
TEST_CASE("Relational operators"){
    for (int i = 1; i <10 ; ++i) {
        for (int j = 1; j < 10; ++j) {
            Fraction a(i,j);
            Fraction b(i*(j-1),j);
            if((j-1)==0){
                CHECK((a>b));
                CHECK((a>=b));
                CHECK((a!=b));
                CHECK_FALSE((a<b));
                CHECK_FALSE((a<=b));
                CHECK_FALSE((a==b));
            }else if((j-1)==1){
                CHECK((a==b));
                CHECK((a<=b));
                CHECK((a>=b));
                CHECK_FALSE((a<b));
                CHECK_FALSE((a>b));
                CHECK_FALSE((a!=b));
            }else{
                CHECK((a<b));
                CHECK((a<=b));
                CHECK((a!=b));
                CHECK_FALSE((a>b));
                CHECK_FALSE((a>=b));
                CHECK_FALSE((a==b));
            }
        }
    }
}
/**
 * * ========================================================================
 * All tests from below will not pass if Relational Operators will not pass.
 * *=========================================================================
 */
TEST_CASE("Unary operators") {
    Fraction a(0, 10);
    int n=0;
    for (int i = 0; i < 5; ++i) {
        CHECK((Fraction(n++,10)==a++));
        CHECK((Fraction(++n,10)==++a));
    }
    CHECK((a==Fraction(10,10)));
    for (int i = 0; i < 5; ++i) {
        CHECK((Fraction(n--,10)==a--));
        CHECK((Fraction(--n,10)==--a));
    }
    CHECK((a==Fraction(0,10)));
}

TEST_CASE("Reduced Forms"){
    Fraction q1(2,8);
    Fraction q2(4,16);
    Fraction ans=q1+q2;
    CHECK(((ans.getNumerator() == 1) && (ans.getDenominator() == 2)));

    ans=(1/4)*q1;
    CHECK(((ans.getNumerator() == 1) && (ans.getDenominator() == 16)));

    Fraction a(6,15);
    Fraction b(15,20);
    Fraction c(11,12);
    int denominator=60;//2*2*3*5 LCM- Least Common multiplier
    int numerator=6*4+15*3+11*5;
    ans=a+b+c;
    CHECK(((ans.getNumerator() == numerator) && (ans.getDenominator() == denominator)));

    ans=a*b;
    CHECK(((ans.getNumerator() == 3) && (ans.getDenominator() == 10)));

    Fraction minus_a(6,-15);
    Fraction id(1,1);
    ans=minus_a*id;
    CHECK(((ans.getNumerator() == -2) && (ans.getDenominator() == 5)));

}
/**
 * adding and multiplying are associative property
 * a*(b*c)=(a*b)*c
 * (a+b)+c=a+(b+c)
 */
TEST_CASE("Associative property"){
    Fraction a(1,3);
    Fraction b(2,5);
    Fraction c(7,11);
    float af=1/3,bf=2/5,cf=7/11;
    CHECK((0==((a+b)+c)-(a+(b+c))));
    CHECK((0==(a*(b*c))-((a*b)*c)));
    CHECK((0==(a*(bf*c))-((af*b)*cf)));
}
/**
 * adding and multiplying are commutative property
 * a+b=b+a
 * a*b=b*a
 */
TEST_CASE("Commutative property"){
    Fraction a(1,3);
    Fraction b(2,5);

    CHECK(((a+b)==(b+a)));
    CHECK(((a*b)==(b*a)));
}
/**
 * distributive property
 * a*b+a*c=a*(b+c)
 */
TEST_CASE("Distributive property"){
    Fraction a(1,3);
    Fraction b(2,5);
    Fraction c(7,11);
    Fraction ans(1,1);
    CHECK((ans==(a*(b+c))));
    CHECK(((a*(b+c))==(a*b+a*c)));
}
/**
 * identity element
 * a*1=a
 * a+0=a
 */
TEST_CASE("Identity element"){
    Fraction a(1,3);
    Fraction i(1,1);
    Fraction zero(0,1);
    CHECK(((i*a)==a));
    CHECK(((a/i)==a));
    CHECK(((a+0)==a));
    CHECK(((a+zero)==a));
}
/**
 * inverse element
 * a*(a^-1)=1
 * a+(-a)=0
 */
TEST_CASE("Inverse element"){
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j <6; ++j) {
            Fraction a(i,j);
            Fraction b(j,i);
            Fraction neg(-i,j);
            Fraction zero(0,1);
            Fraction id(1,1);
            CHECK(((a*b)==id));
            CHECK(((a+neg)==zero));
        }
    }
}