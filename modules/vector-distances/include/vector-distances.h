// Copyright 2022 Maksim Orlov

#ifndef MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_
#define MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_

#include <vector>

class Vector {
 private:
     std::vector<float> data;
 public:
     explicit Vector(const std::vector<float>& _data);
     Vector(const Vector& v);
     Vector& operator=(const Vector& v);
     void setData(const std::vector<float>& v);
     void getData(std::vector<float>* v);
     float Linf(Vector v);
     float L(int p, Vector v);  // Calculates distance according to L_p norm
};

#endif  // MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_
