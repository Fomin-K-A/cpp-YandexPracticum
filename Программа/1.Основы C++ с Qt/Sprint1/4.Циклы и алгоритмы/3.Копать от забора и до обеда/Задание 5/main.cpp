#include <iostream>

int main() {
  int A, B;
  std::cin >> A >> B;
  int step;
  int first;
  int second;

  first = A;
  second = B;

  if (A < B) {
    step = 1;
  } else {
    step = -1;
  }

  for (; first != second + step; first = first+step) {
    if (first % 2 != 0) {
      std::cout << first << std::endl;
    }
  }

  return 0;
}