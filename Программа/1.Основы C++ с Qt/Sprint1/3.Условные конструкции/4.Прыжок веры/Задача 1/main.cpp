#include <iostream>

int main() {
    enum class Weekdays {
        Monday = 1,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    
    int day;
    std::cin >> day;

    switch (static_cast<Weekdays>(day)) {
        case Weekdays::Monday : { 
            std::cout << "Monday" << std::endl;
            break; 
        }
        case Weekdays::Tuesday: {
            std::cout << "Tuesday" << std::endl;
            break;
        }
        case Weekdays::Wednesday: {
            std::cout << "Wednesday" << std::endl;
            break;
        }
        case Weekdays::Thursday: {
            std::cout << "Thursday" << std::endl;
            break;
        }
        case Weekdays::Friday: {
            std::cout << "Friday" << std::endl;
            break;
        }
        case Weekdays::Saturday: {
            std::cout << "Saturday" << std::endl;
            break;
        }
        case Weekdays::Sunday: {
            std::cout << "Sunday" << std::endl;
            break;
        }
        default: {
            std::cout << "Нет такого дня недели" << std::endl;
        }
    }

    return 0;
}