// Copyright 2022 Kazhaeva Anastasia

#ifndef MODULES_KAZHAEVA_COMPLEX_INCLUDE_KAZHAEVA_COMPLEX_H_
#define MODULES_KAZHAEVA_COMPLEX_INCLUDE_KAZHAEVA_COMPLEX_H_


class ComplexNumber {
 public:
    ComplexNumber();
    ComplexNumber(const double real, const double imag);
    ComplexNumber(const ComplexNumber& z);
    ComplexNumber& operator=(const ComplexNumber& z);
    double getRe() const;
    double getIm() const;
    void setRe(const double real);
    void setIm(const double imag);
    ComplexNumber operator + (const ComplexNumber& z) const;
    ComplexNumber operator - (const ComplexNumber& z) const;
    ComplexNumber operator * (const ComplexNumber& z) const;
    ComplexNumber operator / (const ComplexNumber& z) const;
    bool operator == (const ComplexNumber& z) const;
    bool operator != (const ComplexNumber& z) const;
    double magnitude() const;
    double argument()  const;

 private:
    bool equalsZero(const ComplexNumber& z) const;
    double real_;
    double imaginary_;
};

#endif  // MODULES_KAZHAEVA_COMPLEX_INCLUDE_KAZHAEVA_COMPLEX_H_
