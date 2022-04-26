// Copyright 2022 Maksim Orlov

#include "include/vector-distances.h"
#include <vector>
#include <cmath>


Vector::Vector(const std::vector<float>& _data): data(_data) {
}

Vector::Vector(const Vector& v): data(v.data) {
}

Vector& Vector::operator=(const Vector& v) {
    data = v.data;
    return *this;
}

void Vector::setData(const std::vector<float>& v) {
    data = v;
}

void Vector::getData(std::vector<float>* v) {
    *v = data;
}

float Vector::Linf(Vector v) {
    if (data.size() != v.data.size()) throw "Vectors are of different sizes";
    if (data.size() == 0) throw "Vectors are empty";
    float maxDistance = 0;
    for (unsigned int i = 0; i < data.size(); i++) {
        float distance = abs(data[i] - v.data[i]);
        if (distance > maxDistance) maxDistance = distance;
    }
    return maxDistance;
}

float Vector::L(int p, Vector v) {
    if (data.size() != v.data.size()) throw "Vectors are of different sizes";
    if (data.size() == 0) throw "Vectors are empty";
    float sum = 0;
    for (unsigned int i = 0; i < data.size(); i++) {
        sum += pow(abs(data[i] - v.data[i]), p);
    }
    return pow(sum, 1.0f / p);
}
