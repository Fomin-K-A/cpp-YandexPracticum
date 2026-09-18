#include <iostream>
#include <cmath>

int main() {
    double x, y, z;
    std::cout << "Введите стороны треугольника:" << std::endl;
    std::cin >> x >> y >> z;

    double p;
    p = (x + y + z) / 2;
    
    std::cout << "Площадь треугольника: "
        << std::sqrt(p * (p - x) * (p - y) * (p - z)) << std::endl;

    return 0;
}