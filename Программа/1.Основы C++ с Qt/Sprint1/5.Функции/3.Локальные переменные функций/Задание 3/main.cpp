#include <iostream>
#include <cstdint>

std::uint64_t GetFibonacci(int n) {
  std::uint64_t first = 0;
  std::uint64_t second = 1;
  std::uint64_t tmp = 0;
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    for (int i = 1; i != n; i++) {
      tmp = first + second;
      first = second;
      second = tmp;
    }
    return second;
  }
}

int main() {
  int n;
  std::cin >> n;
  std::cout << GetFibonacci(n) << std::endl;
}