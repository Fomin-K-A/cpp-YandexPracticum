#include <string>
#include <iostream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    int number_idx;
    std::cin >> number_idx;

    std::cout << line[number_idx-1] << line[number_idx] << line[number_idx+1] << std::endl;

    return 0;
}