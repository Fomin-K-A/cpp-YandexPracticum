#include <iostream>
#include <string>

void PrintStrStatistics(const std::string& str) {
  auto search = [&](char ch) {
    int counter = 0;
    for (char tmp : str) {
      if (tmp == ch) {
        counter++;
      }
    }
    return counter;
  };

  int num_space = search(' ');

  int num_dot = search('.');

  int num_comma = search(',');

  std::cout << "Пробелов: " << num_space << ", точек: " << num_dot
            << ", запятых: " << num_comma << std::endl;
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  PrintStrStatistics(str);
}