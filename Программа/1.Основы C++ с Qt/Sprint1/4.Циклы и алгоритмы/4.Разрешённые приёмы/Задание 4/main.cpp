#include <iostream>
#include <climits>
#include <cmath>

int main() {
  int N;
  int tmp;
  int cur_max = INT_MIN;
  int cur_next = INT_MIN;

  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    std::cin >> tmp;
    if (tmp > cur_max) {
      cur_next = cur_max;
      cur_max = tmp;
    } else if (tmp > cur_next) {
      cur_next = tmp;
    }
  }

  std::cout << cur_max << " " << cur_next << std::endl;

  return 0;
}
