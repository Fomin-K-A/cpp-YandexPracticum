#pragma once

#include  <utility>

template<typename T>
std::pair<T, T> Swap(std::pair<T, T> pair) {
  T tmp_first = pair.first;
  pair.first = pair.second;
  pair.second = tmp_first;
  return pair;
}