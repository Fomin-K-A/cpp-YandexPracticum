#pragma once

#include <iostream>
#include <optional>
#include <sstream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  if (!opt) {
    os << "Значение не задано";
  } else {
    os << opt.value();
  }
  return os;
}

template<typename T>
std::string ToString(T value) {
    std::ostringstream buffer;
    buffer << value;
    return buffer.str();
}