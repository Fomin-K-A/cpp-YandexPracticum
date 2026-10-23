#include "rational.h"

#include <cstdlib>
#include <numeric>

void Rational::Normalize() {
    if (denominator_ == 0) {
        std::abort();
    }
    // Знаменатель всегда положительный.
    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
    // Сокращаем на НОД.
    const int g = std::gcd(numerator_, denominator_);
    if (g > 1) {
        numerator_ /= g;
        denominator_ /= g;
    }
}

Rational::Rational(int value)
    : numerator_(value)
    , denominator_(1) {
    Normalize();
}

Rational::Rational(int numerator, int denominator)
    : numerator_(numerator)
    , denominator_(denominator) {
    Normalize();
}

int Rational::GetNumerator() const {
    return numerator_;
}

int Rational::GetDenominator() const {
    return denominator_;
}

double Rational::AsDouble() const {
    return static_cast<double>(numerator_) / denominator_;
}

Rational Add(Rational r1, Rational r2) {
    const int num = r1.GetNumerator() * r2.GetDenominator()
                  + r2.GetNumerator() * r1.GetDenominator();
    const int den = r1.GetDenominator() * r2.GetDenominator();
    return Rational{num, den};
}

Rational Sub(Rational r1, Rational r2) {
    const int num = r1.GetNumerator() * r2.GetDenominator()
                  - r2.GetNumerator() * r1.GetDenominator();
    const int den = r1.GetDenominator() * r2.GetDenominator();
    return Rational{num, den};
}