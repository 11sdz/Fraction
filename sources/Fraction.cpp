//
// Created by mintsdz on 4/16/23.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <limits>
using namespace std;

#include "Fraction.hpp"

using namespace ariel;
/**
 * Constructor , creating reduced form Fraction by 2 parameters Integers.
 * @param num - Numerator
 * @param den - Denominator
 */
Fraction::Fraction(int num, int den) {
    if(den==0){
        throw invalid_argument("Denominator cannot be Zero");
    }
    this->num=num;
    this->den=(num==0)? 1: den;
    reducedForm();
}
/**
 * no parameters constructor
 */
Fraction::Fraction() {
    this->num=0;
    this->den=1;
}
/**
 * Constructor transforming float type to Fraction represented by two Integers
 * @param other -float
 */
Fraction::Fraction(float other) {
    this->num=(int)(other*1000);
    this->den=1000;
    reducedForm();
}

/**
 * operator + overloading Fraction+Fraction
 * @param other - Fraction
 * @return the addition of this Fraction + other
 */

Fraction Fraction::operator+(const Fraction other) {
    int numAnswer,denAnswer;
    if((this->den== other.getDenominator()) || (this->num == 0 && other.getNumerator() == 0)){
        numAnswer=this->num+other.num;
        denAnswer= (this->num==0) ? other.getDenominator() : this->den;
    }else{
        numAnswer= (this->num* other.getDenominator()) + (other.getNumerator() * this->den);
        denAnswer=this->den* other.getDenominator();
    }
    if((den>denAnswer)
       || (num>0 && other.getNumerator()>0 && numAnswer<0)
       || (num<0 && other.getNumerator()<0 && numAnswer>0)){
        throw overflow_error("");
    }
    return Fraction(numAnswer,denAnswer);
}
/**
 * operator - overloading Fraction-Fraction
 * @param other -Fraction
 * @return the substraction of this Fraction - other
 */
Fraction Fraction::operator-(const Fraction other) {
    int numAnswer,denAnswer;
    if((this->den== other.getDenominator()) || (this->num == 0 && other.getNumerator() == 0)){
        numAnswer=this->num-other.num;
        denAnswer= (this->num==0) ? other.getDenominator() : this->den;
    }else{
        numAnswer= (this->num* other.getDenominator()) - (other.getNumerator() * this->den);
        denAnswer=this->den* other.getDenominator();
    }
    if(den>denAnswer
       || num<0 && other.getNumerator()>0 && numAnswer>0
       || num>0 && other.getNumerator()<0 && numAnswer<0){
        throw overflow_error("");
    }
    return Fraction(numAnswer,denAnswer);
}

/**
 * operator / division overloading Fraction/Fraction
 * @param other - Fraction
 * @return the Fraction divided by other this/other
 */
Fraction Fraction::operator/(const Fraction other) {
    if(other.getNumerator() == 0){
        throw runtime_error("Cannot divide by Zero");
    }
    if(checkOverflow(this->num,other.getDenominator(),this->den,other.getNumerator())){
        throw overflow_error("");
    }
    int numAnswer,denAnswer;
    numAnswer=this->num* other.getDenominator();
    denAnswer=this->den* other.getNumerator();
    return Fraction(numAnswer,denAnswer);
}
/**
 * operator * multiplication overloading Fraction*Fraction
 * @param other Fraction
 * @return this multiply by other
 */
Fraction Fraction::operator*(const Fraction other) {
    if(checkOverflow(this->num,other.getNumerator(),this->den,other.getDenominator())){
        throw overflow_error("");
    }
    int numAnswer,denAnswer;
    numAnswer=this->num* other.getNumerator();
    denAnswer=this->den* other.getDenominator();
    return Fraction(numAnswer,denAnswer);
}
/**
 * operator + overloading with float type Fraction+float
 * @param other float
 * @return the addition of this with other
 */
Fraction Fraction::operator+(const float other) {
    if(other==0){
        return Fraction(num,den);
    }
    return (*this)+Fraction(other);
}
/**
 * operator - overloading with float type Fraction-float
 * @param other float
 * @return the subtraction of this with other
 */
Fraction Fraction::operator-(const float other) {
    if(other==0){
        return Fraction(num,den);
    }
    return (*this)-Fraction(other);
}
/**
 * operator / overloading with float type Fraction/float
 * @param other float
 * @return the division of this with other
 */
Fraction Fraction::operator/(const float other) {
    if(other==0){
        throw runtime_error("Cannot divide by Zero");
    }
    return (*this)/ Fraction(other);
}
/**
 * operator * overloading with float type Fraction*float
 * @param other float
 * @return the multiplication of this with other
 */
Fraction Fraction::operator*(const float other) {
    return (*this)*Fraction(other);
}
/**
 * postfix addition operator
 * @return this++
 */
Fraction &Fraction::operator++() {
    if((num+den)<num)throw overflow_error("");
    this->num=num+den;
    return *this;
}
/**
 * postfix subtraction operator
 * @return this--;
 */
Fraction &Fraction::operator--() {
    if((num-den)>num)throw overflow_error("");
    this->num=num-den;
    return *this;
}
/**
 * prefix addition operator
 * @return ++this
 */
Fraction Fraction::operator++(int) {
    Fraction temp=*this;
    ++(*this);
    return temp;
}
/**
 * prefix subtraction operator
 * @return --this
 */
Fraction Fraction::operator--(int) {
    Fraction temp=*this;
    --(*this);
    return temp;
}
/**
 * operator + overloading float+Fraction
 * @param flo float
 * @param fra Fraction
 * @return addition of float+Fraction
 */
Fraction operator+(const float flo, const Fraction fra) {
    return Fraction(flo)+fra;
}
/**
 * operator - overloading float-Fraction
 * @param flo float
 * @param fra Fraction
 * @return subtraction of float-Fraction
 */
Fraction operator-(const float flo, const Fraction fra) {
    return Fraction(flo)-fra;
}
/**
 * operator / overloading float/Fraction
 * @param flo float
 * @param fra Fraction
 * @return division of float/Fraction
 */
Fraction operator/(const float flo, const Fraction fra) {
    return Fraction(flo)/fra;
}
/**
 * operator * overloading float*Fraction
 * @param flo float
 * @param fra Fraction
 * @return multiplication  of float*Fraction
 */
Fraction operator*(const float flo, const Fraction fra) {
    return Fraction(flo)*fra;
}
/**
 * operator == overloading float==Fraction
 * @param flo float
 * @param fra Fraction
 * @return  1 if float==Fraction else 0
 */
bool operator==(const float flo, const Fraction fra) {
    return (Fraction(flo)==fra);
}
/**
 * operator != overloading float!=Fraction
 * @param flo float
 * @param fra Fraction
 * @return  1 if float!=Fraction else 0
 */
bool operator!=(const float flo, const Fraction fra) {
    return Fraction(flo)!=fra;
}
/**
 * operator <= overloading float<=Fraction
 * @param flo float
 * @param fra Fraction
 * @return  1 if float<=Fraction else 0
 */
bool operator<=(const float flo, const Fraction fra) {
    return Fraction(flo)<=fra;
}
/**
 * operator >= overloading float>=Fraction
 * @param flo float
 * @param fra Fraction
 * @return  1 if float>=Fraction else 0
 */
bool operator>=(const float flo, const Fraction fra) {
    return Fraction(flo)>=fra;
}
/**
 * operator < overloading float<Fraction
 * @param flo float
 * @param fra Fraction
 * @return  1 if float<Fraction else 0
 */
bool operator<(const float flo, const Fraction fra) {
    return Fraction(flo)<fra;
}
/**
 * operator > overloading float>Fraction
 * @param flo float
 * @param fra Fraction
 * @return  1 if float>Fraction else 0
 */
bool operator>(const float flo, const Fraction fra) {
    return Fraction(flo)>fra;
}
/**
 * operator == overloading Fraction==float
 * @param fra Fraction
 * @param flo float
 * @return  1 if Fraction==float else 0
 */
bool operator==(const Fraction fra, const float flo) {
    return fra==Fraction(flo);
}
/**
 * operator != overloading Fraction!=float
 * @param fra Fraction
 * @param flo float
 * @return  1 if Fraction!=float else 0
 */
bool operator!=(const Fraction fra, const float flo) {
    return fra!=Fraction(flo);
}
/**
 * operator <= overloading Fraction<=float
 * @param fra Fraction
 * @param flo float
 * @return  1 if Fraction<=float else 0
 */
bool operator<=(const Fraction fra, const float flo) {
    return fra<=Fraction(flo);
}
/**
 * operator >= overloading Fraction>=float
 * @param fra Fraction
 * @param flo float
 * @return  1 if Fraction>=float else 0
 */
bool operator>=(const Fraction fra, const float flo) {
    return fra>=Fraction(flo);
}
/**
 * operator < overloading Fraction<float
 * @param fra Fraction
 * @param flo float
 * @return  1 if Fraction<float else 0
 */
bool operator<(const Fraction fra, const float flo) {
    return fra<Fraction(flo);
}
/**
 * operator > overloading Fraction>float
 * @param fra Fraction
 * @param flo float
 * @return  1 if Fraction>float else 0
 */
bool operator>(const Fraction fra, const float flo) {
    return fra>Fraction(flo);
}
/**
 * operator == overloading Fraction==Fraction
 * @param lhs Fraction
 * @param rhs Fraction
 * @return  1 if Fraction==Fraction else 0
 */
bool operator==(const Fraction lhs, const Fraction rhs) {
    return (!(lhs>rhs))&&(!(lhs<rhs));
}
/**
 * operator != overloading Fraction!=Fraction
 * @param lhs Fraction
 * @param rhs Fraction
 * @return  1 if Fraction!=Fraction else 0
 */
bool operator!=(const Fraction lhs, const Fraction rhs) {
    return !(lhs==rhs);
}
/**
 * operator <= overloading Fraction<=Fraction
 * @param lhs Fraction
 * @param rhs Fraction
 * @return  1 if Fraction<=Fraction else 0
 */
bool operator<=(const Fraction lhs, const Fraction rhs) {
    return ((lhs==rhs) || (lhs<rhs));
}
/**
 * operator >= overloading Fraction>=Fraction
 * @param lhs Fraction
 * @param rhs Fraction
 * @return  1 if Fraction>=Fraction else 0
 */
bool operator>=(const Fraction lhs, const Fraction rhs) {
    return ((lhs==rhs) || (lhs>rhs));
}
/**
 * operator < overloading Fraction<Fraction
 * @param lhs Fraction
 * @param rhs Fraction
 * @return  1 if Fraction<Fraction else 0
 */
bool operator<(const Fraction lhs, const Fraction rhs) {
    int numA=lhs.getNumerator(),numB=rhs.getNumerator(),denA=lhs.getDenominator(),denB=rhs.getDenominator();
    numA=numA*denB;
    numB=numB*denA;
    bool res = (numA<numB);
    return res;
}
/**
 * operator > overloading Fraction>Fraction
 * @param lhs Fraction
 * @param rhs Fraction
 * @return  1 if Fraction>Fraction else 0
 */
bool operator>(const Fraction lhs, const Fraction rhs) {
    int numA=lhs.getNumerator(),numB=rhs.getNumerator(),denA=lhs.getDenominator(),denB=rhs.getDenominator();
    numA=numA*denB;
    numB=numB*denA;
    bool res = (numA>numB);
    return res;
}
/*
Fraction &Fraction::operator-() {
    this->num=num*(-1);
    return *this;
}*/
/**
 * cin << operator overloading
 * @param istream1 representing input (legal input string "int int")
 * @param fra Fraction
 * @return Fraction from input
 */
istream &operator>>(istream &istream1, Fraction &fra) {
    stack<char> validate;
    int space=0;
    bool isSpace=true;
    while(isspace(istream1.peek())){
        istream1.get();
    }
    //testing the validation of the input string
    while(istream1.peek()>0){
        char chr= istream1.get();
        if((chr>=48 && chr <=57) || (chr==32) || (chr==45 && isSpace)){
            //if the ASCII character is between 0-9 or space or - (minus)
            validate.push(chr);
            isSpace= false;
            if(isspace(chr)){
                // if the character is space the next character could be - (minus)
                isSpace= true;
                space++; // count the spaces between numbers
            }
        }else{
            //if the ASCII character is not a number or space or minus invalid arguments
            throw runtime_error("");
        }
    }
    while(!validate.empty()){
        //building back the istream
        istream1.putback(validate.top());
        validate.pop();
    }
    istream1 >> fra.num >> fra.den;
    if(fra.den==0 || space<1){
        //space <1 only one Integer | Denominator cannot be zero
        throw runtime_error("invalid input");
    }
    fra.reducedForm();
    return istream1;
}
/**
 * cout operator overloading
 * @param ostream1 cout
 * @param fra Fraction
 * @return string represets the Fraction "Numerator/Denominator"
 */
ostream &operator<<(ostream &ostream1, const Fraction &fra) {
    ostream1 <<fra.num << "/" << fra.den;
    return ostream1;
}
/**
 * getter Numerator
 * @return num - Numerator
 */
int Fraction::getNumerator() const{
    return num;
}
/**
 * getter Denominator
 * @return den - Denominator
 */
int Fraction::getDenominator() const{
    return den;
}
/**function to reduce form the Fraction using the gcd
 * (Numerator/gcd)/(Denominator/gcd)
 * https://en.wikipedia.org/wiki/Irreducible_fraction
 */
void Fraction::reducedForm() {
    int gcd= std::__gcd(this->num,this->den);
    this->num=num/gcd;
    this->den=den/gcd;
    if(den<0){
        this->num=(-1)*this->num;
        this->den=(-1)*this->den;
    }
    return;
}
/**
 * method to check if overflow error has happened
 * by using the inequalities num1*num2>max => num1>max/num2 logic
 * @param num1
 * @param num2
 * @param num3
 * @param num4
 * @return 1 if overflow if everything is correct return 0
 */
bool Fraction::checkOverflow(int num1, int num2, int num3, int num4) {
    if(num1==0 || num2==0 || num3==0 || num4 == 0){
        return false;
    }
    int maximum=numeric_limits<int>::max();
    int minimum=numeric_limits<int>::min();
    if(num1>0 && num2<0){
        int temp=num1;
        num1=num2;
        num2=temp;
    }else if(num1<0 && num2<0){
        num1= abs(num1);
        num2= abs(num2);
    }
    if(num3>0 && num4 < 0){
        int temp=num3;
        num3=num4;
        num4=temp;
    }else if(num3<0 && num4 < 0){
        num3= abs(num3);
        num4= abs(num4);
    }
    if((num1> maximum/num2) || (num3> maximum / num4) || (num1 < minimum / num2) || (num3 < minimum / num4)){
        return true;
    }
    return false;
}
