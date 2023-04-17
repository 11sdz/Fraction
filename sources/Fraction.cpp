//
// Created by mintsdz on 4/16/23.
//

#include <iostream>
using namespace std;

#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(int num, int den) {
    this->num=num;
    this->den=den;
}

Fraction::Fraction() {
    this->num=0;
    this->den=1;
}

Fraction Fraction::operator+(const Fraction other) {
    return Fraction();
}

Fraction Fraction::operator-(const Fraction other) {
    return Fraction();
}

Fraction Fraction::operator/(const Fraction other) {
    return Fraction();
}

Fraction Fraction::operator*(const Fraction other) {
    return Fraction();
}

Fraction Fraction::operator+(const float other) {
    return Fraction();
}

Fraction Fraction::operator-(const float other) {
    return Fraction();
}

Fraction Fraction::operator/(const float other) {
    return Fraction();
}

Fraction Fraction::operator*(const float other) {
    return Fraction();
}

Fraction &Fraction::operator++() {
    return *this;
}

Fraction &Fraction::operator--() {
    return *this;
}

Fraction Fraction::operator++(int) {
    return Fraction();
}

Fraction Fraction::operator--(int) {
    return Fraction();
}

bool Fraction::operator==(const Fraction other) {
    return false;
}

bool Fraction::operator!=(const Fraction other) {
    return false;
}

bool Fraction::operator<=(const Fraction other) {
    return false;
}

bool Fraction::operator>=(const Fraction other) {
    return false;
}

bool Fraction::operator<(const Fraction other) {
    return false;
}

bool Fraction::operator>(const Fraction other) {
    return false;
}

Fraction operator+(const float flo, const Fraction fra) {
    return Fraction();
}

Fraction operator-(const float flo, const Fraction fra) {
    return Fraction();
}

Fraction operator/(const float flo, const Fraction fra) {
    return Fraction();
}

Fraction operator*(const float flo, const Fraction fra) {
    return Fraction();
}

bool operator==(const float flo, const Fraction fra) {
    return false;
}

bool operator!=(const float flo, const Fraction fra) {
    return false;
}

bool operator<=(const float flo, const Fraction fra) {
    return false;
}

bool operator>=(const float flo, const Fraction fra) {
    return false;
}

bool operator<(const float flo, const Fraction fra) {
    return false;
}

bool operator>(const float flo, const Fraction fra) {
    return false;
}

bool operator==(const Fraction fra, const float flo) {
    return false;
}

bool operator!=(const Fraction fra, const float flo) {
    return false;
}

bool operator<=(const Fraction fra, const float flo) {
    return false;
}

bool operator>=(const Fraction fra, const float flo) {
    return false;
}

bool operator<(const Fraction fra, const float flo) {
    return false;
}

bool operator>(const Fraction fra, const float flo) {
    return false;
}

Fraction &Fraction::operator-() {
    return *this;
}



istream &operator>>(istream &istream1, Fraction &fra) {
    istream1 >> fra.num >> fra.den;
    return istream1;
}

ostream &operator<<(ostream &ostream1, const Fraction &fra) {
    ostream1 << fra.num << "/" << fra.den;
    return ostream1;
}

int Fraction::getNum() const {
    return num;
}

int Fraction::getDen() const {
    return den;
}
