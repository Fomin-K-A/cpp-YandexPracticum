#include <iostream>
#include <cmath>

int main() {
	double room_length;
	double room_width;
	double room_height;
	double roll_length;
	double roll_width;

	std::cin >> room_length >> room_width >> room_height;
	std::cin >> roll_width >> roll_length;

	double first_pair_walls = room_length * room_height * 2;
	double second_pair_walls = room_width * room_height * 2;

	double room_s = first_pair_walls + second_pair_walls;
	double roll_s = roll_length * roll_width;

	int rolls_value = std::ceil(room_s / roll_s);

	std::cout << rolls_value;

	return 0; 
}