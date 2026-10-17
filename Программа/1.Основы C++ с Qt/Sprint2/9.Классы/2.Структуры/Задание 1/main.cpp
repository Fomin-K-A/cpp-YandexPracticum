#include <iostream>

struct Cat {
  std::string name;
  int age;
};

using namespace std::literals;

int main() {
  Cat cat;
  cat.name = "Leopold"s;
  cat.age = 3;

  std::cout << cat.name << " is now " << cat.age << " years old" << std::endl;
  return 0;
}