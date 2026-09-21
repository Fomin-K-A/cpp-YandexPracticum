#include <string>
#include <iostream>

int main() {
    int first, second;
    std::cin >> first >> second;

    if (first > second) {
        std::cout << "Число " << first << " больше" << std::endl;
    }
    else if (first == second) {
        std::cout << "Числа равны" << std::endl;
    }
    else {
        std::cout << "Число " << second << " больше" << std::endl;
    }

    return 0;
}