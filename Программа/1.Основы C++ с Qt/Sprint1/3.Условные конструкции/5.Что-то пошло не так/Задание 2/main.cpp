#include <iostream>

int main() {
	int n;
	std::cin >> n;

	n % 2 == 0 ? std::cout << "Число " << n << " чётное" << std::endl : std::cout << "Число " << n << " нечётное";

	return 0;
}