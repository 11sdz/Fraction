//
// Created by mintsdz on 4/16/23.
//

#ifndef FRACTION_FRACTION_HPP
#define FRACTION_FRACTION_HPP

#include <ostream>

using namespace std;
namespace ariel{

}
class Fraction{
    private:
        int num,den;
    public:
        int getNum() const;

        int getDen() const;
        Fraction(int,int);
        Fraction();

        Fraction& operator-();

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

        bool operator==(Fraction other);
        bool operator!=(Fraction other);
        bool operator<=(Fraction other);
        bool operator>=(Fraction other);
        bool operator<(Fraction other);
        bool operator>(Fraction other);

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


    friend istream &operator>>(istream &istream1, Fraction &fra);
    friend ostream &operator<<(ostream &ostream1, const Fraction &fra);
};
#endif //FRACTION_FRACTION_HPP
