#include <iostream>
#include <string>

int main() {
  double number;
  std::cin >> number;

  std::string op;

  double total = 0;
  double term = number;  
  int sign = 1;          

  while (true) {
    std::cin >> op;

    if (op == "*") {
      double tmp;
      std::cin >> tmp;
      term = term * tmp;  
    } else if (op == "/") {
      double tmp;
      std::cin >> tmp;
      term = term / tmp;  
    } else if (op == "+") {
      total += sign * term;  
      sign = 1;            
      std::cin >> term;     
    } else if (op == "-") {
      total += sign * term;  
      sign = -1;             
      std::cin >> term;     
    } else if (op == "=") {
      total += sign * term; 
      std::cout << total << std::endl;
      return 0;
    } else {
      std::cerr << "Error!" << std::endl;
      return 0;
    }
  }
}