#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string line;
  std::getline(std::cin, line);

  bool is_digit = false;
  int n = 0;

  for (char ch : line) {
    if (std::isdigit(ch)) {
      if (is_digit == false) {
        n++;
      }
      is_digit = true;
    } else {
      is_digit = false;
    }
  }
  
  std::cout << n;

  return 0;
}