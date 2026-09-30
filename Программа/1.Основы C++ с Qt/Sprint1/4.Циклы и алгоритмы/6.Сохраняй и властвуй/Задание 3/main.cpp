#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string str_number;
  std::cin >> str_number;
  int n = str_number.size();

  std::vector<int> number;

  for (int i = n; i != 0; i--) {
    number.push_back(static_cast<int>(str_number[i - 1]) - '0');
  }
  for (int i = 0; i < n; i++) {
    if (number[i] + 1 > 9) {
      number[i] = 0;
      if (i == n - 1) {
        number.push_back(1);
        n++;
        break;
      }
      continue;
    } else if (number[i] + 1 < 10) {
      number[i] = number[i] + 1;
      break;
    }
  }

  for (int i = n; i != 0; i--) {
    std::cout << number[i - 1];
  }

  return 0;
}