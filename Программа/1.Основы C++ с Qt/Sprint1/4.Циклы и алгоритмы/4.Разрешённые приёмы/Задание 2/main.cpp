#include <cstdint>
#include <iostream>

int main() {
  int n;

  std::uint64_t result = 1;
  std::cin >> n;
  if (n < 1 || n > 63) {
    std::cout << "Wrong input" << std::endl;
    return 0;
  }
  bool is_first = true;
  for (int i = 1; i <= n; ++i) {
    if (!is_first) {
      std::cout << ", ";
    }
    result = result * 2;
    std::cout << result;
    is_first = false;
  }

  return 0;
}