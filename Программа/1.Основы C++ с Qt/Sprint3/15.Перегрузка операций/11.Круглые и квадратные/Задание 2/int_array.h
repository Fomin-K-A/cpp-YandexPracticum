#pragma once

#include <vector>
#include <cmath>

class IntArray {
 public:
  IntArray(std::vector<int> data) : data_(data) {}

  void push_back(int value) { data_.push_back(value); }

  int operator[](int index) {
    if (index >= 0 && index < data_.size()) {
      return data_[index];
    } else if (std::abs(index) - 1 < data_.size()) {
      return data_[data_.size()+index];
    }
    return 9999;
  }
 
 private:
  std::vector<int> data_;
};