#include <iostream>

int main() {
	int first;
	int last;
	int delta;
	int n;
	int result;

	std::cin >> first >> delta >> n;

	last = delta * (n-1) + first;
	result = (first + last) * n / 2;

	std::cout << last << std::endl
		      << result << std::endl;

	return 0; 
}