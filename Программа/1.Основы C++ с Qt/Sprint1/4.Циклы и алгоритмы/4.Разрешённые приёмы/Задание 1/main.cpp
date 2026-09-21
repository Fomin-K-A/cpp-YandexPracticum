#include <iostream>

int main() {
  int n;
  int tmp;
  double result = 0;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    result += tmp;
  }

  std::cout << result / n << std::endl;
  return 0;
}