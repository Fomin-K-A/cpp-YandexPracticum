#include <iostream>
#include <cstdint>

std::uint64_t GetFactorial(int n) {
  if (n > 1) {
    return n * GetFactorial(n - 1);
  }
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << GetFactorial(n) << std::endl;
}