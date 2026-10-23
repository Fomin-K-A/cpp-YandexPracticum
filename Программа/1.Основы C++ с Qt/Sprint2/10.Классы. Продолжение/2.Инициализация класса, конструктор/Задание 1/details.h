#pragma once

struct Point {
    double x = 0;
    double y = 0;

    Point() = default;
    Point(double x_, double y_) : x(x_), y(y_) {}
};

struct Triangle {
    Point p1;
    Point p2;
    Point p3;

    Triangle() = default;
    Triangle(Point a, Point b, Point c) : p1(a), p2(b), p3(c) {}
};