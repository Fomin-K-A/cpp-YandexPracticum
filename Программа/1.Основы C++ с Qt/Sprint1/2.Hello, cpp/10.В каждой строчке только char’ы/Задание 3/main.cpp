#include <string>
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int summ = a + b;
    std::string summ_str = std::to_string(a) + std::to_string(b);
    int decrease = std::stoi(summ_str) - summ;

    std::cout << summ << std::endl
              << summ_str << std::endl
              << decrease << std::endl;

    return 0;
}