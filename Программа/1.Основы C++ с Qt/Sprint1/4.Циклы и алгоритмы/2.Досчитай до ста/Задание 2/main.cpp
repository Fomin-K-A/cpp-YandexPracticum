#include <iostream>

int main() {
  int num;
  std::cin >> num;

  do {
    std::cout << num % 10;
    num = num / 10;
  } while (num > 0);

  return 0;
}