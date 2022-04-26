// Copyright 2022 Labinskaya Marina
#ifndef MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_OPERATIONS_H_
#define MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_OPERATIONS_H_

#include <vector>
#include <stdexcept>
#include <cmath>

/* This class describes a three-dimensional vector and some
operations with it: finding the norm, normalization, scalar
and vector multiplication */

class Vector3d {
 public:
    Vector3d();
    Vector3d(double x, double y, double z);
    double& operator[](double pos);
    const double& operator[](double pos) const;
    double get_norm();
    Vector3d get_normalization();
    static double scalar_mult(const Vector3d& v1, const Vector3d& v2);
    static Vector3d vector_mult(const Vector3d& v1, const Vector3d& v2);
 private:
    std::vector<double> data;
};

#endif  // MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_OPERATIONS_H_
