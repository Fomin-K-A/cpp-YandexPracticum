#pragma once

// Структура для хранения обычных унций.
struct Ounce {
  double count;
  inline static double grams = 28.3495;
};

// Структура для хранения тройских унций.
struct OunceTroy {
  double count;
  inline static double grams = 31.1;
};

template <typename T>
int CompareOunces(const T& a, const T& b) {
  if (a.count < b.count) {
    return -1;
  }
  if (b.count < a.count) {
    return 1;
  }
  return 0;
}

template <typename T, typename U>
int CompareOunces(const T& a, const U& b) {
  double weight_a = a.count * T::grams;
  double weight_b = b.count * U::grams;

  if (weight_a < weight_b) {
    return -1;
  }
  if (weight_b < weight_a) {
    return 1;
  }
  return 0;
}