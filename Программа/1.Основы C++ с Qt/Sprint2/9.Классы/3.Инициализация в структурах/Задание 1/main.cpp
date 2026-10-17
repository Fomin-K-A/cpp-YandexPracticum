#include<cassert>

struct Point {
  double x = 0;
  double y = 0;
};

int main() {
  Point p;
  assert(p.x == 0.);
  assert(p.y == 0.);
}