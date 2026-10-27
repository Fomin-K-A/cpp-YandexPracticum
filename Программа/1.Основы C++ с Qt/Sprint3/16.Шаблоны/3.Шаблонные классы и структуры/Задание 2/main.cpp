#include <iostream>
#include <utility>

#include "geometry.h"

int main() {
  Triangle<int> tr_int;
  Triangle<std::pair<int, int>> tr_pair;
  Triangle<Point<int>> tr_point;

  std::cin >> tr_int;
  std::cin >> tr_pair;
  std::cin >> tr_point;

  std::cout << tr_int << std::endl;
  std::cout << tr_pair << std::endl;
  std::cout << tr_point << std::endl;
}