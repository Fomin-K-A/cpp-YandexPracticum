#pragma once

#include <cmath>
#include <iomanip>
#include <iostream>

template <int W, int R>
class UniverseModel {
 public:
  static double CountTotalVolume() {
    if constexpr (W > W_CONST) {
      return (4.0 / 3.0) * M_PI * std::pow(R, 3);
    } else if constexpr (W == W_CONST) {
      return std::pow(R, 2);
    } else {
      return 2.0 * std::pow(M_PI, 2) * std::pow(R * 0.5, 2) * R;
    }
  }

  double CountStars(double stars_per_unit) const {
    return total_volume * stars_per_unit;
  }

 private:
  inline static constexpr double W_CONST = 8;

  inline static const double total_volume = CountTotalVolume();
};

template <typename T>
void CountStarsStats(T UniverseModel) {
  using namespace std::literals;

  std::cout << "Stars per unit  Total number of stars"s << std::endl;
  for (int i = 1; i <= 10; i++) {
    std::cout << std::setw(10) << i;
    std::cout << std::setw(20) << UniverseModel.CountStars(i) << std::endl;
  }
}