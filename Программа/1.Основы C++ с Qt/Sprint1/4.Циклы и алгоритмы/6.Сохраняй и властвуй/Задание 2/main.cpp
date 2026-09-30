#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::vector<std::string> vect;

  for (int i = 0; i < n; ++i) {
    std::string line;
    std::getline(std::cin, line);
    vect.push_back(line);
  }
  int k;
  std::cin >> k;

  for (int i = vect.size()-1; k != 0; k--, i--) {
    std::cout << i << " " << vect[i] << std::endl;
  }

  return 0;
}
