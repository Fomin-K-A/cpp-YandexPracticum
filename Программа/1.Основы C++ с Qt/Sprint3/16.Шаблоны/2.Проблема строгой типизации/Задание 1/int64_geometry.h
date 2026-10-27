#pragma once

#include <cstdint>
#include <iostream>

// Хранит координаты точки.
struct PointInt64 {
    int64_t x;
    int64_t y;
};

// Выводит координаты точки.
inline std::ostream& operator<<(std::ostream& os, const PointInt64& point) {
    os << "(" << point.x << "; " << point.y << ")";
    return os;
}

// Хранит отрезок, заданный двумя точками.
class Vector2DInt64 {
public:
    Vector2DInt64(PointInt64 p1, PointInt64 p2)
        : point1_(p1), point2_(p2) {}

    int64_t GetLengthSq() const {
        int64_t dx = point2_.x - point1_.x;
        int64_t dy = point2_.y - point1_.y;

        return dx * dx + dy * dy;
    }

private:
    PointInt64 point1_;
    PointInt64 point2_;
};