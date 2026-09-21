#include <iostream>
#include <string>

int main() {
  double a, b;
  std::string op;

  if (std::cin >> a >> op >> b) {
    if (op == "+") {
      std::cout << a + b;
    } else if (op == "-") {
      std::cout << a - b;
    } else if (op == "*") {
      std::cout << a * b;
    } else if (op == "/") {
      std::cout << a / b;
    } else {
      std::cerr << "Incorrect operation" << std::endl;
    }
  } else {
    std::cerr << "Incorrect input" << std::endl;
  }

  return 0;
}