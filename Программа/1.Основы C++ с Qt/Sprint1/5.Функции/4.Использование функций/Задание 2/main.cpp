#include <cassert>
#include <iostream>
#include <string>

int CharToDigit(char ch) {
  if (ch >= '0' && ch <= '9') {
    return ch - '0';
  } else if (ch >= 'A' && ch <= 'Z') {
    return ch - 'A' + 10;
  } else {
    return ch - 'a' + 10;
  }
}

int StringToNumber(std::string s, int base) {
  int result = 0;
  int tmp_base = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    result = result + CharToDigit(s[i])*tmp_base;
    tmp_base = tmp_base * base;
  }
  return result;
}

int main() {
  std::string src_string;
  int src_base;

  std::cin >> src_string >> src_base;

  int number = StringToNumber(src_string, src_base);

  std::cout << number << std::endl;
}