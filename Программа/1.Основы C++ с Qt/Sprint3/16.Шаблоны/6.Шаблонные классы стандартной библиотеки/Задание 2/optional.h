#pragma once

#include <iostream>
#include <optional>
#include <sstream>

template<typename T>
std::istream& operator>>(std::istream& is, std::optional<T>& opt) {
  T value;
  if (is >> value) {
    opt = value;
  } else {
    is.clear();
  }
  return is;
}

template <typename T>
std::optional<T> FromString(std::string str) {
  std::istringstream is(str);
  std::optional<T> opt;
  is >> opt;
  return opt;
}