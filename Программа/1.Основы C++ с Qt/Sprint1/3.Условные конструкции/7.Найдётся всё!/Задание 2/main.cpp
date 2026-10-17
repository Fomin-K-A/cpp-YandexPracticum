#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);

    const std::string correct_symbols = 
         "abcdefghijklmnopqrstuvwxyz"
         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
         "0123456789._-+@";

    size_t pointer;
    size_t sobaka;

    sobaka = line.find('@');
    if (sobaka == std::string::npos) {
      std::cout << "Некорректный email" << std::endl;
      return 0;
    } 

    pointer = line.find('@', sobaka+1);
    if (pointer != std::string::npos) {
      std::cout << "Некорректный email" << std::endl;
      return 0;
    }

    pointer = line.find('.',sobaka+1);
    if (pointer == sobaka + 1 || pointer == std::string::npos) {
      std::cout << "Некорректный email" << std::endl;
      return 0;
    }

    pointer = line.rfind('.');
    if (pointer == line.size()-1) {
      std::cout << "Некорректный email" << std::endl;
      return 0;
    }

    pointer = line.find_first_not_of(correct_symbols);
    if (pointer != std::string::npos) {
      std::cout << "Некорректный email" << std::endl;
      return 0;
    }
    std::cout << "Корректный email" << std::endl;

    return 0;
}