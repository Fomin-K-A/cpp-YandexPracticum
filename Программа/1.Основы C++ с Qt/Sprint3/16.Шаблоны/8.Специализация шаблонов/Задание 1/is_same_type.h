#pragma once

template <class T, class U>
struct IsSameType {
  static constexpr bool value = false;
};

template <class T>
struct IsSameType<T, T> {
  static constexpr bool value = true;
};

template <class T, class U>
inline constexpr bool IsSameTypeV = IsSameType<T, U>::value;