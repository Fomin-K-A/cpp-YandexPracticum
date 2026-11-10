
#pragma once

#include <cmath>

template <typename T>
struct Point {
    T x;
    T y;
};

template <typename T>
class Vector2D {
public:
    Vector2D(Point<T> p_start, Point<T> p_end)
        : start_(p_start), end_(p_end) {
    }

    // Считает квадрат длины.
    T GetLengthSq() const {
        T dx = end_.x - start_.x;
        T dy = end_.y - start_.y;
        return dx * dx + dy * dy;
    }

    // Присваивает начало отрезка.
    void SetStart(Point<T> start) {
        start_ = start;
    }

    // Присваивает конец отрезка.
    void SetEnd(Point<T> end) {
        end_ = end;
    }

    // Возвращает начало отрезка.
    Point<T> GetStart() const {
        return start_;
    }

    // Возвращает конец отрезка.
    Point<T> GetEnd() const {
        return end_;
    }

private:
    Point<T> start_;
    Point<T> end_;
};
