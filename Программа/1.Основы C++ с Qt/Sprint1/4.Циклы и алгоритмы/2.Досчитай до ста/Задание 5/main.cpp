#include <cctype>
#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string type;  // Тип регистра: upper или lower.
  std::string str;
  std::getline(std::cin, type);
  std::getline(std::cin, str);

  if (type == "lower") {
    for (int i = 0; i < str.size(); i++) {
      if (std::isalpha(str[i])) {
        str[i] = tolower(str[i]);
      }
    }
  } else {
    for (int i = 0; i < str.size(); i++) {
      if (std::isalpha(str[i])) {
        str[i] = toupper(str[i]);
      }
    }
  }
  std::cout << str;

  return 0;
}