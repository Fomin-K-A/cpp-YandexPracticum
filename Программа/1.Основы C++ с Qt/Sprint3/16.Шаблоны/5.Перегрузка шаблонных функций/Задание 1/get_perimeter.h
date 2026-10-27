#pragma once

template<typename T>
T GetPerimeter(T number) {
  return number * 4;
}

template<typename T,typename D>
auto GetPerimeter(T number1, D number2) {
  return (number1 + number2) * 2;
}

template<typename T,typename D,typename F,typename G>
auto GetPerimeter(T a, D b, F c, G d) {
  return a + b + c + d;
}