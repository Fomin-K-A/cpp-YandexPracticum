#pragma once
#include <iostream>

template <typename T>
struct Point {
  T x{}, y{};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
  return os << "(" << point.x << "; " << point.y << ")";
}

template <typename T>
std::istream& operator>>(std::istream& is, Point<T>& point) {
  return is >> point.x >> point.y;
}

template <typename T>
class Vector2D {
 public:
  Vector2D() = default;
  Vector2D(Point<T> p_start, Point<T> p_end) : start_(p_start), end_(p_end) {}

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Vector2D<U>& vec);

  template <typename U>
  friend std::istream& operator>>(std::istream& is, Vector2D<U>& vec);

 private:
  Point<T> start_{};
  Point<T> end_{};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& vec) {
  return os << "[" << vec.start_ << ", " << vec.end_ << "]";
}

template <typename T>
std::istream& operator>>(std::istream& is, Vector2D<T>& vec) {
  return is >> vec.start_ >> vec.end_;
}