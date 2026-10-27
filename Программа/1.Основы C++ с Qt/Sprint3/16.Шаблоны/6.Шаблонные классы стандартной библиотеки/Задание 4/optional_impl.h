#pragma once

template <typename T>
class Optional {
 public:
  Optional() = default;

  Optional(const T& value) : has_value_(true), value_(value) {}

  bool HasValue() const { return has_value_; }

  T GetValue() const { return value_; }

  void SetValue(T value) {
    value_ = value;
    has_value_ = true;
  }

  void Reset() {
    has_value_ = false;
  }

 private:
  bool has_value_ = false;
  T value_; 
};