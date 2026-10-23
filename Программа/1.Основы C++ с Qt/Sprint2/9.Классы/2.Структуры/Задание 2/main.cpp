#include <iostream>

struct Person {
  std::string name;
  std::string surname;
};

using namespace std::literals;

int main() {
  Person person1;
  Person person2 = {"Hermione", "Granger"};
  person1.name = "Harry";
  person1.surname = "Potter";

  std::cout << person1.name << " " << person1.surname << std::endl;
  std::cout << person2.name << " " << person2.surname << std::endl;

  return 0;
}