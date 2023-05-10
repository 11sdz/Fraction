//
// Created by mintsdz on 4/16/23.
//

#ifndef FRACTION_FRACTION_HPP
#define FRACTION_FRACTION_HPP

#include <ostream>

using namespace std;
namespace ariel{
/*
 * Fraction class - represents Fraction by Numerator/Denominator
 */
}
class Fraction{
    private:
        int num,den;
        void reducedForm();
        bool checkOverflow(int num1,int num2,int den1,int num4);

    public:
        Fraction(float other);
        int getNumerator() const;

        int getDenominator() const;
        Fraction(int,int);
        Fraction();

        //Fraction& operator-();

        Fraction operator+(Fraction other);
        Fraction operator-(Fraction other);
        Fraction operator/(Fraction other);
        Fraction operator*(Fraction other);

        Fraction operator+(float other);
        Fraction operator-(float other);
        Fraction operator/(float other);
        Fraction operator*(float other);

        Fraction& operator++();
        Fraction& operator--();
        Fraction operator++(int);
        Fraction operator--(int);

    friend Fraction operator+(float flo,Fraction fra);
    friend Fraction operator-( float flo, Fraction fra);
    friend Fraction operator/( float flo, Fraction fra);
    friend Fraction operator*( float flo, Fraction fra);

    friend bool operator==( float flo, Fraction fra);
    friend bool operator!=( float flo, Fraction fra);
    friend bool operator<=( float flo, Fraction fra);
    friend bool operator>=( float flo, Fraction fra);
    friend bool operator<( float flo, Fraction fra);
    friend bool operator>( float flo, Fraction fra);


    friend bool operator==( Fraction fra, float flo);
    friend bool operator!=( Fraction fra, float flo);
    friend bool operator<=( Fraction fra, float flo);
    friend bool operator>=( Fraction fra, float flo);
    friend bool operator<( Fraction fra, float flo);
    friend bool operator>( Fraction fra, float flo);

    friend bool operator==( Fraction lhs, Fraction rhs);
    friend bool operator!=( Fraction lhs, Fraction rhs);
    friend bool operator<=( Fraction lhs, Fraction rhs);
    friend bool operator>=( Fraction lhs, Fraction rhs);
    friend bool operator<( Fraction lhs, Fraction rhs);
    friend bool operator>( Fraction lhs, Fraction rhs);


    friend istream &operator>>(istream &istream1, Fraction &fra);
    friend ostream &operator<<(ostream &ostream1, const Fraction &fra);

};
#endif //FRACTION_FRACTION_HPP
