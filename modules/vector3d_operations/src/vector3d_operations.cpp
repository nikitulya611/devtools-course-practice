// Copyright 2022 Labinskaya Marina

#include "include/vector3d_operations.h"

Vector3d::Vector3d(): data{ 0.0, 0.0, 0.0 } {}

Vector3d::Vector3d(double x, double y, double z): data { x, y, z } {}

double& Vector3d::operator[](double pos) {
    if (pos < 0 || pos > 2)
        throw std::out_of_range("Vector subscript out of range.");
    return data[pos];
}

const double& Vector3d::operator[](double pos) const {
    if (pos < 0 || pos > 2)
        throw std::out_of_range("Vector subscript out of range.");
    return data[pos];
}

double Vector3d::get_norm() {
    return std::sqrt(scalar_mult(*this, *this));
}

Vector3d Vector3d::get_normalization() {
    double norm = this->get_norm();
    if (!norm) {
        throw std::domain_error("Null vector has no normalization.");
    }

    Vector3d res(data[0] / norm, data[1] / norm, data[2] / norm);
    return res;
}

double Vector3d::scalar_mult(const Vector3d& v1, const Vector3d& v2) {
    return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

Vector3d Vector3d::vector_mult(const Vector3d& v1, const Vector3d& v2) {
    Vector3d result;
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = -(v1[0] * v2[2] - v1[2] * v2[0]);
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];

    return result;
}
