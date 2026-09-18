#include <iostream>

int main() {
	int players = 0;
	std::cin >> players;

	std::cout << R"(Эники, беники ели вареники,
Эники, беники съели вареники,
Эники, беники, хоп!)" << std::endl;

	std::cout << 10 % players;

	return 0;
}