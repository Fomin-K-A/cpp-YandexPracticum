#include <iostream>

int main() {
	double pumpkin_weight = 0.15;
	double pumpkin_cost = 0.0;
	double onion_weight = 0.05;
	double onion_cost = 0.0;
	double carrot_weight = 0.05;
	double carrot_cost = 0.0;
	double coconut_milk_weight = 0.1;
	double coconut_milk_cost = 0.0;
	int portion_value = 0;

	std::cout << "Тыква" << std::endl;
	std::cin >> pumpkin_cost;

	std::cout << "Лук" << std::endl;
	std::cin >> onion_cost;

	std::cout << "Морковь" << std::endl;
	std::cin >> carrot_cost;

	std::cout << "Кокосовое молоко" << std::endl;
	std::cin >> coconut_milk_cost;

	std::cout << "Количество порций" << std::endl;
	std::cin >> portion_value;

	pumpkin_cost = pumpkin_cost * pumpkin_weight;
	onion_cost = onion_cost * onion_weight;
	carrot_cost = carrot_cost * carrot_weight;
	coconut_milk_cost = coconut_milk_cost * coconut_milk_weight;

	double result_cost = (pumpkin_cost + onion_cost + carrot_cost + coconut_milk_cost)*portion_value;

	std::cout << "Стоимость: " << result_cost << std::endl;

	return 0; 
}