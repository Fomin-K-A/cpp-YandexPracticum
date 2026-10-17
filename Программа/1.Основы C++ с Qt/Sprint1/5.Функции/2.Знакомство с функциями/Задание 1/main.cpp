#include <cctype>
#include <iostream>
#include <string>

void PrintUpper(std::string str) {
  for (char ch : str) {
    std::cout << static_cast<char>(std::toupper(ch));
  }
  std::cout<<std::endl;
  return;
}

void PrintLower(std::string str) {
  for (char ch : str) {
    std::cout << static_cast<char>(std::tolower(ch));
  }
  std::cout << std::endl;
  return;
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  PrintUpper(str);
  PrintLower(str);
}