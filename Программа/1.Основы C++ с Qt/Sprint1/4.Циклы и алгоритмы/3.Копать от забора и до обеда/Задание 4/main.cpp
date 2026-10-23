#include <iostream>

int main() {
  int n;
  std::cin >> n;

  for (size_t i = 0; i <= n; ++i) {
    std::cout << n - i << std::endl;
  }

  std::cout << "GO!" << std::endl;

  return 0;
}