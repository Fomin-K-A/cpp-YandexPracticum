#include <iostream>

int main() {
  int N, M;
  std::cin >> N >> M;

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      if ((n + m) % 2 == 0) {
        std::cout << "o ";
      } else {
        std::cout << "x ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}