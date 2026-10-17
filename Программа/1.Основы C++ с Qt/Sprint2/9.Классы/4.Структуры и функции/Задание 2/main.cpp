#include <iostream>
#include <cmath>

struct Point {
  double x = 0.0;
  double y = 0.0;
};

struct Vector2D {
  double x = 0.0;
  double y = 0.0;
};

Point ReadPoint() { 
  double x;
  double y;
  std::cin >> x >> y;
  return Point{x, y};
}

void PrintPoint(Point p) { std::cout << "{" << p.x << ", " << p.y << "}"; }

Vector2D PointDifference(Point p1, Point p2) {
  double x = p2.x - p1.x;
  double y = p2.y - p1.y;
  return Vector2D{x, y};
}

void PrintVector(Vector2D v) {
  std::cout << "(" << v.x << ", " << v.y << ")" << std::endl;
}

double FindLength(Vector2D v) { return std::hypot(v.x, v.y); }

int main() {
  Point p1 = ReadPoint();
  Point p2 = ReadPoint();
  Vector2D v = PointDifference(p1, p2);

  PrintVector(v);
  std::cout << std::endl;

  std::cout << FindLength(v) << std::endl;
}