#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Вывод для pair.
template <typename F, typename S>
std::ostream& operator<<(std::ostream& os, const std::pair<F, S>& p) {
  using namespace std::literals;
  return os << "("s << p.first << "; "s << p.second << ")"s;
}

template <typename T>
std::string ToString(const std::vector<T>& v) {
  std::ostringstream oss;
  for (size_t i = 0; i < v.size(); ++i) {
    if (i > 0) {
      oss << ", ";
    }
    oss << v[i];  
  }
  return oss.str();
}