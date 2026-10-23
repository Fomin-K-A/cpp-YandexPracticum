#include <iostream>
#include <string>

int main() {
  std::string op;
  double number;

  if (!(std::cin >> number)) {
    std::cerr << "Error: Numeric operand expected" << std::endl;
  } else {
    while (true) {
      std::cin >> op;
      if (op == "+") {
        double tmp;
        if (!(std::cin >> tmp)) {
          std::cerr << "Error: Numeric operand expected";
          return 0;
        } else {
          number = number + tmp;
          std::cout << number << std::endl;
        }
      } else if (op == "q") {
        return 0;
      } else {
        std::cerr << "Error: Unknown token " << op << std::endl;
        return 0;
      }
    }
  }
}