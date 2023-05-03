//
// Created by mintsdz on 4/16/23.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <limits.h>
#include <limits>
using namespace std;

#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(int num, int den) {
    if(den==0){
        throw invalid_argument("Denominator cannot be Zero");
    }
    this->num=num;
    this->den=(num==0)? 1: den;
    reducedForm();
}

Fraction::Fraction() {
    this->num=0;
    this->den=1;
}

bool Fraction::checkOverflow(int num1, int num2, int den1, int den2) {
    if(num1==0 || num2==0 || den1==0 || den2==0){
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
    if(den1>0 && den2<0){
        int temp=den1;
        den1=den2;
        den2=temp;
    }else if(den1<0 && den2<0){
        den1= abs(den1);
        den2= abs(den2);
    }
    if((num1> maximum/num2) || (den1> maximum/den2) ||(num1<minimum/num2) ||(den1<minimum/den2)){
        return true;
    }
    return false;
}

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

Fraction Fraction::operator*(const Fraction other) {
    if(checkOverflow(this->num,other.getNumerator(),this->den,other.getDenominator())){
        throw overflow_error("");
    }
    int numAnswer,denAnswer;
    numAnswer=this->num* other.getNumerator();
    denAnswer=this->den* other.getDenominator();
    return Fraction(numAnswer,denAnswer);
}

Fraction Fraction::operator+(const float other) {
    if(other==0){
        return Fraction(num,den);
    }
    return (*this)+Fraction(other);
}

Fraction Fraction::operator-(const float other) {
    if(other==0){
        return Fraction(num,den);
    }
    return (*this)-Fraction(other);
}

Fraction Fraction::operator/(const float other) {
    if(other==0){
        throw runtime_error("Cannot divide by Zero");
    }
    return (*this)/ Fraction(other);
}

Fraction Fraction::operator*(const float other) {
    return (*this)*Fraction(other);
}

Fraction &Fraction::operator++() {
    if((num+den)<num)throw overflow_error("");
    this->num=num+den;
    return *this;
}

Fraction &Fraction::operator--() {
    if((num-den)>num)throw overflow_error("");
    this->num=num-den;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp=*this;
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(int) {
    Fraction temp=*this;
    --(*this);
    return temp;
}
//
//bool Fraction::operator==(const Fraction other) {
//    return !(((*this)>other)||((*this)<other));
//}
//
//bool Fraction::operator!=(const Fraction other) {
//    return !((*this)==other);
//}
//
//bool Fraction::operator<=(const Fraction other) {
//    return ((*this)<other) || ((*this)==other);
//}
//
//bool Fraction::operator>=(const Fraction other) {
//    return ((*this)>other) || ((*this)==other);
//}
//
//bool Fraction::operator<(const Fraction other) {
//    int numA = this->num* other.getDenominator();
//    int numB = other.getNumerator() * this->den;
//    return numA<numB;
//}
//
//bool Fraction::operator>(const Fraction other) {
//    int numA = this->num* other.getDenominator();
//    int numB = other.getNumerator() * this->den;
//    return numA>numB;
//}

Fraction operator+(const float flo, const Fraction fra) {
    return Fraction(flo)+fra;
}

Fraction operator-(const float flo, const Fraction fra) {
    return Fraction(flo)-fra;
}

Fraction operator/(const float flo, const Fraction fra) {
    return Fraction(flo)/fra;
}

Fraction operator*(const float flo, const Fraction fra) {
    return Fraction(flo)*fra;
}

bool operator==(const float flo, const Fraction fra) {
    return (Fraction(flo)==fra);
}

bool operator!=(const float flo, const Fraction fra) {
    return Fraction(flo)!=fra;
}

bool operator<=(const float flo, const Fraction fra) {
    return Fraction(flo)<=fra;
}

bool operator>=(const float flo, const Fraction fra) {
    return Fraction(flo)>=fra;
}

bool operator<(const float flo, const Fraction fra) {
    return Fraction(flo)<fra;
}

bool operator>(const float flo, const Fraction fra) {
    return Fraction(flo)>fra;
}

bool operator==(const Fraction fra, const float flo) {
    return fra==Fraction(flo);
}

bool operator!=(const Fraction fra, const float flo) {
    return fra!=Fraction(flo);
}

bool operator<=(const Fraction fra, const float flo) {
    return fra<=Fraction(flo);
}

bool operator>=(const Fraction fra, const float flo) {
    return fra>=Fraction(flo);
}

bool operator<(const Fraction fra, const float flo) {
    return fra<Fraction(flo);
}

bool operator>(const Fraction fra, const float flo) {
    return fra>Fraction(flo);
}

bool operator==(const Fraction lhs, const Fraction rhs) {
    return (!(lhs>rhs))&&(!(lhs<rhs));
}

bool operator!=(const Fraction lhs, const Fraction rhs) {
    return !(lhs==rhs);
}

bool operator<=(const Fraction lhs, const Fraction rhs) {
    return ((lhs==rhs) || (lhs<rhs));
}

bool operator>=(const Fraction lhs, const Fraction rhs) {
    return ((lhs==rhs) || (lhs>rhs));
}

bool operator<(const Fraction lhs, const Fraction rhs) {
    int numA=lhs.getNumerator(),numB=rhs.getNumerator(),denA=lhs.getDenominator(),denB=rhs.getDenominator();
    numA=numA*denB;
    numB=numB*denA;
    bool res = (numA<numB);
    return res;
}

bool operator>(const Fraction lhs, const Fraction rhs) {
    int numA=lhs.getNumerator(),numB=rhs.getNumerator(),denA=lhs.getDenominator(),denB=rhs.getDenominator();
    numA=numA*denB;
    numB=numB*denA;
    bool res = (numA>numB);
    return res;
}

Fraction &Fraction::operator-() {
    this->num=num*(-1);
    return *this;
}

istream &operator>>(istream &istream1, Fraction &fra) {
    stack<char> validate;
    int space=0;
    bool isSpace=true;
    while(isspace(istream1.peek())){
        istream1.get();
    }
    while(istream1.peek()>0){
        char chr= istream1.get();
        if((chr>=48 && chr <=57) || (chr==32) || (chr==45 && isSpace)){
            validate.push(chr);
            isSpace= false;
            if(isspace(chr)){
                isSpace= true;
                space++;
            }
        }else{
            throw runtime_error("");
        }
    }
    while(!validate.empty()){
        istream1.putback(validate.top());
        validate.pop();
    }
    istream1 >> fra.num >> fra.den;
    if(fra.den==0 || space<1){
        throw runtime_error("invalid input");
    }
    fra.reducedForm();
    return istream1;
}

ostream &operator<<(ostream &ostream1, const Fraction &fra) {
    ostream1 <<fra.num << "/" << fra.den;
    return ostream1;
}

int Fraction::getNumerator() const{
    return num;
}

int Fraction::getDenominator() const{
    return den;
}

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


Fraction::Fraction(float other) {
    this->num=(int)(other*1000);
    this->den=1000;
}
