#pragma once

#include <optional>
#include <tuple>
#include <vector>

template<typename T>
std::optional<std::tuple<T, int, T, int>> FindMinMax(std::vector<T> v) {
  if (v.empty()) {
    return std::nullopt;
  }

  T min = v[0];
  T max = v[0];
  int min_indx = 0;
  int max_indx = 0;

  for (int i = 0; i < v.size(); i++) {
    if (min > v[i]) {
      min = v[i];
      min_indx = i;
    }
    if (max < v[i]) {
      max = v[i];
      max_indx = i;
    }
  }

  return std::make_tuple(min, min_indx, max, max_indx);
}