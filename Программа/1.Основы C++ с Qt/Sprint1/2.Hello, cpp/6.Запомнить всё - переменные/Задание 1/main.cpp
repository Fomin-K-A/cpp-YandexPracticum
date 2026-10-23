#include <iostream>

int main() {
  double first;
  double second;

  std::cin >> first >> second;

  std::cout << "Сумма: " << first + second << std::endl
            << "Разность: " << first - second << std::endl
            << "Произведение: " << first * second << std::endl
            << "Отношение: " << first / second;
}