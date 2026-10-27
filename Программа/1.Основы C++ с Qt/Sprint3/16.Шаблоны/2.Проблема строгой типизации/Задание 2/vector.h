#pragma once
#include <iostream>

struct PointInt {
    PointInt() = default;
    PointInt(int x0, int y0)
       : x(x0), y(y0) {}

    int x = 0;
    int y = 0;
};

struct PointDouble {
    PointDouble() = default;
    PointDouble(double x0, double y0)
       : x(x0), y(y0) {}

    double x = 0;
    double y = 0;
};

class Vector2DInt { 
public:
    Vector2DInt(PointInt p_start, PointInt p_end)
      : start_(p_start)
      , end_(p_end)
    {
    }
    
    int GetLengthSq() const {
        int dx = start_.x - end_.x;
        int dy = start_.y - end_.y;
        return dx * dx + dy * dy;
    }
    
    bool CheckAxisIntersection() {
        bool intersectsOY =
            (start_.x <= 0 && end_.x >= 0) ||
            (start_.x >= 0 && end_.x <= 0);

        bool intersectsOX =
            (start_.y <= 0 && end_.y >= 0) ||
            (start_.y >= 0 && end_.y <= 0);

        return intersectsOY || intersectsOX;
    }


private:
    PointInt start_;
    PointInt end_;
};

class Vector2DDouble { 
public:
    Vector2DDouble(PointDouble p_start, PointDouble p_end)
      : start_(p_start)
      , end_(p_end)
    {
    }
    
    double GetLengthSq() const {
        double dx = start_.x - end_.x;
        double dy = start_.y - end_.y;
        return dx * dx + dy * dy;
    }
    
    bool CheckAxisIntersection() {
    bool intersectsOY =
        (start_.x <= 0 && end_.x >= 0) ||
        (start_.x >= 0 && end_.x <= 0);

    bool intersectsOX =
        (start_.y <= 0 && end_.y >= 0) ||
        (start_.y >= 0 && end_.y <= 0);

    return intersectsOY || intersectsOX;
}
    
private:
    PointDouble start_;
    PointDouble end_;
};