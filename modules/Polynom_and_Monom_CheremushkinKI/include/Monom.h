// Copyright 2022 Cheremushkin Kirill
#ifndef MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_MONOM_H_
#define MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_MONOM_H_
#pragma once
#include <iostream>
class Monom {
 private:
    double Coef;  // Coefecnt  monoma
    int degree;  // Degree monoma
    Monom* NextMonom = NULL;  // Source on next monom
    Monom* BackMonom = NULL;  // Source on back monom

 public:
    Monom();  // Konstuctor monoma
    Monom(double coef, int degree);  // Konstuctor monoma with parameters
    Monom(const Monom& tmp);  // Konstuctor copy monoma

    Monom& operator=(const Monom& tmp);  // Addition, subtraction,
    Monom operator+(const Monom& tmp)const;  // multiplication
    Monom operator-(const Monom& tmp)const;  // division, equation operators
    Monom operator*(const Monom& tmp)const;
    Monom operator/(const Monom& tmp)const;

    ~Monom();  // Destuctor monoma

    Monom* GetNextMonom();  // Heters and seters
    void SetNextMonom(const Monom& tmp);
    Monom* GetBackMonom();
    void SetBackMonom(const Monom& tmp);
    Monom* GetCurrentMonom();
    int GetDegree()const;
    void SetDegree(int deg);
    double GetCoef()const;
    void SetCoef(double coef);
};
#endif  // MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_MONOM_H_
