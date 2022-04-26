// Copyright 2022 Ermakov Pavel

#include "include/ermakov_pavel_tringle_params.h"
#include <math.h>
#include <utility>

_Triangle::_Triangle() {
    this->a = { 0, 0 };
    this->b = { 2, 4 };
    this->c = { 4, 0 };
}

_Triangle::_Triangle(std::pair<float, float> _a, std::pair<float, float> _b,
    std::pair<float, float> _c) {
    this->a = _a;
    this->b = _b;
    this->c = _c;
}

std::pair<float, float> _Triangle::get_a_poin() {
    return this->a;
}

std::pair<float, float> _Triangle::get_b_poin() {
    return this->b;
}

std::pair<float, float> _Triangle::get_c_poin() {
    return this->c;
}

void _Triangle::set_a_poin(std::pair<float, float> _p) {
    this->a = _p;
}

void _Triangle::set_b_poin(std::pair<float, float> _p) {
    this->b = _p;
}

void _Triangle::set_c_poin(std::pair<float, float> _p) {
    this->c = _p;
}

float _Triangle::get_perimetr() {
    float _ab = this->get_side_lenght(this->a, this->b);
    float _bc = this->get_side_lenght(this->b, this->c);
    float _ca = this->get_side_lenght(this->c, this->a);
    float res = _ab + _bc + _ca;
    return res;
}

float _Triangle::get_square() {
    float pp = this->get_perimetr() / 2;
    float _ab = this->get_side_lenght(this->a, this->b);
    float _bc = this->get_side_lenght(this->b, this->c);
    float _ca = this->get_side_lenght(this->c, this->a);
    float res = sqrt(pp * (pp - _ab) * (pp - _bc) * (pp - _ca));
    return res;
}

float _Triangle::get_height(float _side) {
    float res = 2 / _side * this->get_square();
    return res;
}

float _Triangle::get_side_lenght(std::pair<float, float> _a,
    std::pair<float, float> _b) {
    float _ac = _b.first - _a.first;
    float _bc = _b.second - _a.second;
    float res = sqrt((_ac * _ac) + (_bc * _bc));
    return res;
}

_Triangle::~_Triangle() {
    this->a = { 0, 0 };
    this->b = { 0, 0 };
    this->c = { 0, 0 };
}
