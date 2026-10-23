#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> line(n);
  for (int i = 0; i < n; i++) {
    std::cin >> line[i];
  }

  int counter = 0;
  for (int i = 0; i < n; i++) {
    bool is_unique = true;
    for (int j = 0; j < n; j++) {
      if (i != j && line[i] == line[j]) {
        is_unique = false;
        break;
      }
    }
    if (is_unique) {
      counter++;
    }
  }

  std::cout << counter << std::endl;
  return 0;
}