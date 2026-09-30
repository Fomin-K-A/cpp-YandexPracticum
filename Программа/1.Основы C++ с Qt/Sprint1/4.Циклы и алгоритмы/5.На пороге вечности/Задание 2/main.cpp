#include <iostream>
#include <string>

int main() {
  std::string lit;
  std::getline(std::cin, lit);

  for (int i = 1; i < lit.size()-1; ++i) {
    if (lit[i] == '\\') {
      if (lit[i + 1] == 'n') {
        std::cout << "\n";
        i++;
        continue;
      } else if (lit[i + 1] == '\\') {
        std::cout << '\\';
        i++;
        continue;
      } else if (lit[i + 1] == '\"') {
        std::cout << '\"';
        i++;
        continue;
      } else if (lit[i + 1] == '0') {
        i++;
        break;
      }
    } 
    std::cout << lit[i];
  }

  return 0;
}