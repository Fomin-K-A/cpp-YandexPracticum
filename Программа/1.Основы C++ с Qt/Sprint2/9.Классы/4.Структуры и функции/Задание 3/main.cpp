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

struct Triangle {
  Point p1;
  Point p2;
  Point p3;
};

Triangle ReadTriangle() {
  double x;
  double y;
  std::cin >> x >> y;
  Point p1{x, y};
  std::cin >> x >> y;
  Point p2{x, y};
  std::cin >> x >> y;
  Point p3{x, y};
  return Triangle{p1, p2, p3};
}

Vector2D PointDifference(Point p1, Point p2) {
  double x = p2.x - p1.x;
  double y = p2.y - p1.y;
  return Vector2D{x, y};
}

void PrintVector(Vector2D v) {
  std::cout << "(" << v.x << ", " << v.y << ")" << std::endl;
}

double FindLength(Vector2D v) { return std::hypot(v.x, v.y); }

double FindPerimeter(const Triangle& t) {
  return FindLength(PointDifference(t.p1, t.p2)) + FindLength(PointDifference(t.p2, t.p3)) +
                    FindLength(PointDifference(t.p3, t.p1));
}

int main() {
  Triangle t = ReadTriangle();
  std::cout << FindPerimeter(t) << std::endl;
}