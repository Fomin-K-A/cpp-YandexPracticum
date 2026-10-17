#include <string>
#include <iostream>

int main() {
    std::string password = "COOLPETYA111";
    std::string input;

    std::cin >> input;

    if (input == password) {
        std::cout << "Пароль верный" << std::endl;
        return 0;
    }
    std::cout << "Пароль неверный" << std::endl;

    return 0;
}