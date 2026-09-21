#include <iostream>
#include <cmath>

int main() {
  int amount;
  double rate;
  int term;

  std::cin >> amount >> rate >> term;

  double month_rate;
  double ratio;
  double month_payment;
  double percent_part;
  double debt_part;
  double debt = amount;
  for (int i = 1; i < term + 1; i++) {
    month_rate = rate / 12 / 100;
    ratio = (std::pow(1 + month_rate, term) * month_rate) /
                   (std::pow(1 + month_rate, term) - 1);
    month_payment = amount * ratio;
    percent_part = debt * month_rate;
    debt_part = month_payment - percent_part;
    debt = debt - debt_part;
    std::cout << "Месяц: " << i << " Платёж: " << month_payment
              << " Проценты: " << percent_part << " Долг: " << debt_part
              << std::endl;
  }

  return 0;
}