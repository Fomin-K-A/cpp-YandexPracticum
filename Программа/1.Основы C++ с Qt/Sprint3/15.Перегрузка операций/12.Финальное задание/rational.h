
#pragma once

#include <compare>
#include <iostream>
#include <numeric>
#include <stdexcept>

class Rational {
 public:
  Rational() : numerator_(0), denominator_(1) {}

  Rational(int num) : numerator_(num), denominator_(1) { Reduction(); }

  Rational(int num, int denom) : numerator_(num), denominator_(denom) {
    if (denominator_ == 0) {
      throw std::invalid_argument("Zero denominator");
    }
    Reduction();
  }

  Rational(const Rational& tmp)
      : numerator_(tmp.numerator_), denominator_(tmp.denominator_) {
    Reduction();
  }

  int GetNumerator() const { return numerator_; }

  int GetDenominator() const { return denominator_; }

  Rational Inv() const { return Rational(denominator_, numerator_); }

  Rational& operator=(const Rational& other) {
    if (this != &other) {
      numerator_ = other.numerator_;
      denominator_ = other.denominator_;
      Reduction();
    }
    return *this;
  }

  Rational operator+() const { return *this; }

  Rational operator-() const { return Rational(-numerator_, denominator_); }

  Rational& operator+=(const Rational& other) {
    numerator_ =
        numerator_ * other.denominator_ + other.numerator_ * denominator_;
    denominator_ *= other.denominator_;
    Reduction();
    return *this;
  }

  Rational& operator-=(const Rational& other) {
    numerator_ =
        numerator_ * other.denominator_ - other.numerator_ * denominator_;
    denominator_ *= other.denominator_;
    Reduction();
    return *this;
  }

  Rational& operator*=(const Rational& other) {
    numerator_ *= other.numerator_;
    denominator_ *= other.denominator_;
    Reduction();
    return *this;
  }

  Rational& operator/=(const Rational& other) {
    if (other.numerator_ == 0) {
      throw std::invalid_argument("Division by zero");
    }

    numerator_ *= other.denominator_;
    denominator_ *= other.numerator_;
    Reduction();
    return *this;
  }

  friend Rational operator+(Rational lhs, const Rational& rhs) {
    lhs += rhs;
    return lhs;
  }

  friend Rational operator-(Rational lhs, const Rational& rhs) {
    lhs -= rhs;
    return lhs;
  }

  friend Rational operator*(Rational lhs, const Rational& rhs) {
    lhs *= rhs;
    return lhs;
  }

  friend Rational operator/(Rational lhs, const Rational& rhs) {
    lhs /= rhs;
    return lhs;
  }

  bool operator==(const Rational& other) const {
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
  }

  std::strong_ordering operator<=>(const Rational& other) const {
    long long left = static_cast<long long>(numerator_) * other.denominator_;
    long long right = static_cast<long long>(other.numerator_) * denominator_;

    return left <=> right;
  }

  friend std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.numerator_;

    if (r.denominator_ != 1) {
      out << " / " << r.denominator_;
    }

    return out;
  }

  friend std::istream& operator>>(std::istream& in, Rational& r) {
    int num = 0;
    int denom = 1;

    if (!(in >> num)) {
      return in;
    }

    if (!in.eof()) {
      in >> std::ws;

      if (!in.eof() && in.peek() == '/') {
        in.get();

        if (!(in >> denom)) {
          return in;
        }
      }
    }

    if (denom == 0) {
      in.setstate(std::ios::failbit);
      return in;
    }

    r = Rational(num, denom);
    return in;
  }

 private:
  int numerator_;
  int denominator_;

  void Reduction() {
    if (denominator_ < 0) {
      numerator_ = -numerator_;
      denominator_ = -denominator_;
    }

    const int divisor = std::gcd(numerator_, denominator_);
    numerator_ /= divisor;
    denominator_ /= divisor;
  }
};