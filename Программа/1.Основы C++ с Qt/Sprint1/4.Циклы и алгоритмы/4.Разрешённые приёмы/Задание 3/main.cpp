#include <iostream>
#include <cmath>
#include <climits>

int main() {
  int N;
  int tmp;
  std::cin >> N;

  int max = INT_MIN;
  int min = INT_MAX;

  for (int i = 0; i < N; ++i) {
    std::cin >> tmp;
    if (tmp > max) {
      max = tmp;
    }
    if (tmp < min) {
      min = tmp;
    }
  }

  std::cout << min << " " << max << std::endl;

  return 0;
}