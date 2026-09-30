#include <iostream>
#include <vector>

int main() {
  std::vector<char> abc{'a', 'b', 'c', 'd'};

  for (char ch1 : abc) {
    for (char ch2 : abc) {
      for (char ch3 : abc) {
        if (ch1 == ch2 || ch1 == ch3 || ch2 == ch3) {
          std::cout << ch1 << ch2 << ch3 << std::endl;
        }
      }
    }
  }

  return 0;
}