// Copyright 2022 Vanyushkov Maxim

#include <gtest/gtest.h>

#include "include/ratio.h"

int Ratio::gcd(int a, int b) const {
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

Ratio::Ratio(int _numerator, int _denominator) {
    if (_denominator == 0) {
        throw "Error! Division by ZERO";
    }
    if (_denominator < 0 && _numerator) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }
    if (_numerator == 0 || _denominator == 1) {
        numerator = _numerator;
        denominator = 1;
    } else {
        int divider = gcd(std::abs(_numerator), _denominator);
        numerator = _numerator / divider;
        denominator = _denominator / divider;
    }
}

Ratio::Ratio(const Ratio& r) {
    numerator = r.numerator;
    denominator = r.denominator;
}

Ratio& Ratio::operator=(const Ratio& r) {
    numerator = r.numerator;
    denominator = r.denominator;
    return *this;
}

Ratio Ratio::operator+ (const Ratio& r) const {
    return Ratio(numerator * r.denominator + r.numerator * denominator,
        denominator * r.denominator);
}

Ratio Ratio::operator- (const Ratio& r) const {
    return Ratio(numerator * r.denominator - r.numerator * denominator,
        denominator * r.denominator);
}

Ratio Ratio::operator* (const Ratio& r) const {
    return Ratio(numerator * r.numerator, denominator * r.denominator);
}

Ratio Ratio::operator/ (const Ratio& r) const {
    return Ratio(numerator * r.denominator, denominator * r.numerator);
}

Ratio Ratio::operator+ () const {
    return Ratio(numerator, denominator);
}

Ratio Ratio::operator- () const {
    return Ratio(-numerator, denominator);
}

bool Ratio::operator== (const Ratio& r) const {
    return numerator == r.numerator && denominator == r.denominator;
}

bool Ratio::operator!= (const Ratio& r) const {
    return numerator != r.numerator || denominator != r.denominator;
}

bool Ratio::operator> (const Ratio& r) const {
    return numerator * r.denominator > r.numerator * denominator;
}

bool Ratio::operator< (const Ratio& r) const {
    return numerator * r.denominator < r.numerator * denominator;
}

bool Ratio::operator>= (const Ratio& r) const {
    return *this == r || *this > r;
}

bool Ratio::operator<= (const Ratio& r) const {
    return *this == r || *this < r;
}

int Ratio::div() const {
    return numerator / denominator;
}

int Ratio::mod() const {
    if (numerator > 0) {
        return numerator % denominator;
    }
    return denominator - (std::abs(numerator) % denominator);
}

double Ratio::to_double() const {
    return static_cast<double>(numerator) / denominator;
}

int Ratio::get_numerator() const {
    return numerator;
}

int Ratio::get_denominator() const {
    return denominator;
}

void Ratio::set_ratio(int _numerator, int _denominator) {
    if (_denominator == 0) {
        throw "Error! Division by ZERO";
    }
    if (_denominator < 0 && _numerator) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }
    if (_numerator == 0 || _denominator == 1) {
        numerator = _numerator;
        denominator = 1;
    } else {
        int divider = gcd(std::abs(_numerator), _denominator);
        numerator = _numerator / divider;
        denominator = _denominator / divider;
    }
}
