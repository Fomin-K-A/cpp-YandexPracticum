#include <iostream>

int main() {
  int cost, banknote;
  int number_banknote = 0;
  std::cin >> cost;
  do {
    ++number_banknote;
    std::cin >> banknote;
    if (cost <= banknote) {
      std::cout << number_banknote << " " << banknote - cost << " " << banknote
                << std::endl;
      return 0;
    } else {
      cost -= banknote;
    }
  } while (true);
}