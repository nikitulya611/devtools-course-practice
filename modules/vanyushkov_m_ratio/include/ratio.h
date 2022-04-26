// Copyright 2022 Vanyushkov Maxim

#ifndef MODULES_VANYUSHKOV_M_RATIO_INCLUDE_RATIO_H_
#define MODULES_VANYUSHKOV_M_RATIO_INCLUDE_RATIO_H_

class Ratio {
 private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const;

 public:
    explicit Ratio(int _numerator = 0, int _denominator = 1);
    Ratio(const Ratio& r);
    Ratio& operator=(const Ratio& r);

    Ratio operator+ (const Ratio& r) const;
    Ratio operator- (const Ratio& r) const;
    Ratio operator* (const Ratio& r) const;
    Ratio operator/ (const Ratio& r) const;
    Ratio operator+ () const;
    Ratio operator- () const;

    bool operator== (const Ratio& r) const;
    bool operator!= (const Ratio& r) const;
    bool operator> (const Ratio& r) const;
    bool operator< (const Ratio& r) const;
    bool operator>= (const Ratio& r) const;
    bool operator<= (const Ratio& r) const;

    int div() const;
    int mod() const;
    double to_double() const;

    int get_numerator() const;
    int get_denominator() const;

    void set_ratio(int _numerator, int _denominator);
};

#endif  // MODULES_VANYUSHKOV_M_RATIO_INCLUDE_RATIO_H_
