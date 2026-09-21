#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string line;
  std::getline(std::cin, line);

  bool previous_is_alpha = false;

  for (int i = 0; i < line.size();i++){
    std::cout << line[i];
    if (isalpha(line[i])) {
      previous_is_alpha = true;
      continue;
    }
    if (isdigit(line[i]) && previous_is_alpha == true) {
      break;
    } else {
      previous_is_alpha = false;
    }
  }

  return 0;
}