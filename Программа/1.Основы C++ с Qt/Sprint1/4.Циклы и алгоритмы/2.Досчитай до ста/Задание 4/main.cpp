#include <iostream>
#include <string>

int main() {
  std::string line;
  int len = 0;
  int num = 0;

  std::getline(std::cin, line);
  while (line.size() > 0) {
    len += line.size();
    ++num;

    std::getline(std::cin, line);
  }

  std::cout << num << " " << len;

  return 0;
}