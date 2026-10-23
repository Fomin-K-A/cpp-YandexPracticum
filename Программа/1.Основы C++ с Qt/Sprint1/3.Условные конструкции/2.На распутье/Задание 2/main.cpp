#include <string>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "Число " << n << " чётное" << std::endl;
        return 0;
    }
    std::cout << "Число " << n << " нечётное" << std::endl;

    return 0;
}