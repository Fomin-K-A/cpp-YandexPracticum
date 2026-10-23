#pragma once

class Rational {
public:
    Rational() = default;
    Rational(int value);
    Rational(int numerator, int denominator);

    int GetNumerator() const;
    int GetDenominator() const;
    double AsDouble() const;

private:
    void Normalize();

    int numerator_ = 0;
    int denominator_ = 1;
};

Rational Add(Rational r1, Rational r2);
Rational Sub(Rational r1, Rational r2);