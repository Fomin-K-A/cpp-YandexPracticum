#include <cassert>
#include <iostream>

int CharToDigit(char ch) {
  if (ch >= '0' && ch <= '9') {
    return ch - '0';
  } else if (ch >= 'A' && ch <= 'Z') {
    return ch - 'A' + 10;
  } else {
    return ch - 'a' + 10;
  }
}

int main() {
  char ch;
  std::cin >> ch;

  const int digit_value = CharToDigit(ch);

  std::cout << digit_value << std::endl;

  return 0;
}