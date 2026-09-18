#include <iostream>

int main() {
    int day_number;
    int days_pass;

    std::cin >> day_number >> days_pass;

    int weekend_pass = days_pass / 7;
    int new_day_number = (day_number + days_pass - 1) % 7 + 1;

    std::cout << weekend_pass << std::endl
              << new_day_number << std::endl;

    return 0;
}