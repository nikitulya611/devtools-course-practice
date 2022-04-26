// Copyright 2022 Cheremushkin Kirill
#include <include/Monom.h>

Monom::Monom() {
    this->Coef = 0;
    this->degree = 0;
    this->NextMonom = NULL;
}

Monom::Monom(double coef, int degree) {
    Coef = coef;
    this->degree = degree;
    NextMonom = NULL;
}

Monom::Monom(const Monom& tmp) {
    Coef = tmp.Coef;
    degree = tmp.degree;
    NextMonom = tmp.NextMonom;
}

Monom & Monom::operator=(const Monom& tmp) {
    Coef = tmp.Coef;
    degree = tmp.degree;
    NextMonom = tmp.NextMonom;
    return *this;
}

Monom Monom::operator+(const Monom& tmp) const {
    if (degree != tmp.degree) {
        std::cout << "Error -1 -1" << std::endl;
        Monom f(-1, -1);
        return f;
    }
    double res = this -> Coef + tmp.Coef;
    Monom Res = Monom(res, this -> degree);
    return Res;
}

Monom Monom::operator-(const Monom& tmp) const {
    if (degree != tmp.degree) {
        std::cout << "Error -1 -1" << std::endl;
        Monom f(-1, -1);
        return f;
    }
    double res = this->Coef - tmp.Coef;
    Monom Res = Monom(res, this->degree);
    return Res;
}

Monom Monom::operator*(const Monom& tmp) const {
    int Degre = this->degree + tmp.degree;
    double coef = this->Coef * tmp.Coef;
    Monom Res = Monom(coef, Degre);
    return Res;
}

Monom Monom::operator/(const Monom& tmp) const  {
    int Degree = this->degree - tmp.degree;
    if (tmp.Coef == 0.0) {
        std::cout << "rithg Degree=0 -> Error" <<
        std::endl << "Comeback -1 -1 ";
        Monom Res = Monom(-1, -1);
        return Res;
    }
    if (this->Coef == 0.0) {
        double coef = 0;
        Monom Res = Monom(coef, Degree);
        return Res;
    }
    double coef = this->Coef/tmp.Coef;
    Monom Res = Monom(coef, Degree);
    return Res;
}

Monom::~Monom()  {
    Coef = 0;
    degree = 0;
    NextMonom = NULL;
    delete NextMonom;
}

Monom* Monom::GetNextMonom() {
    return NextMonom;
}

void Monom::SetNextMonom(const Monom& tmp) {
    delete NextMonom;
    NextMonom = new Monom();
    NextMonom->SetCoef(tmp.GetCoef());
    NextMonom->SetDegree(tmp.GetDegree());
}

Monom* Monom::GetBackMonom() {
    return BackMonom;
}

void Monom::SetBackMonom(const Monom& tmp) {
    delete BackMonom;
    BackMonom = new Monom();
    BackMonom->SetCoef(tmp.GetCoef());
    BackMonom->SetDegree(tmp.GetDegree());
}

Monom* Monom::GetCurrentMonom() {
    return this;
}

int Monom::GetDegree()const {
    return degree;
}

void Monom::SetDegree(int deg) {
    degree = deg;
}

double Monom::GetCoef()const {
    return Coef;
}

void Monom::SetCoef(double coef) {
    Coef = coef;
}
