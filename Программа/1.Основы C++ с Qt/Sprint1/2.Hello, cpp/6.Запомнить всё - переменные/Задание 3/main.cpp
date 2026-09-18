#include <iostream>

int main() {
	double farengeit_degree = 0.0;

	std::cout << "Введите температуру в градусах Фаренгейта:" << std::endl;
	
	std::cin >> farengeit_degree;

	double celsious_degree = (farengeit_degree - 32) * 5 / 9;

	std::cout << "Температура в градусах Цельсия: " << celsious_degree << std::endl;

	return 0;
}