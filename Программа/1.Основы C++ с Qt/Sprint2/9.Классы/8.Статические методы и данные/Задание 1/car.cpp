#include "car.h"

bool Car::IsEngineOn() {
    return engine_is_on_;
}

bool Car::SetGear(Gear new_gear) {
    if (gear_ == new_gear) {
        return true;
    }
    if (!engine_is_on_) {
        return false;
    }
    if (speed_ != 0) {
        return false;
    }
    gear_ = new_gear;
    return true;
}

Gear Car::GetGear() {
    return gear_;
}

int Car::GetSpeed() {
    return speed_;
}

bool Car::SetSpeed(int new_speed) {
    if (!engine_is_on_ || new_speed < 0) {
        return false;
    }
    if (speed_ == new_speed) {
        return true;
    }
    if (!IsSpeedValidForGear(new_speed, gear_)) {
        return false;
    }
    speed_ = new_speed;
    return true;
}

Direction Car::GetDirection() {
    if (gear_ == Gear::PARKED || speed_ == 0) {
        return Direction::STOPPED;
    }
    if (gear_ == Gear::DRIVE) {
        return Direction::FORWARD;
    }
    return Direction::BACKWARD;
}

void Car::TurnEngineOn() {
    engine_is_on_ = true;
}

bool Car::TurnEngineOff() {
    if (engine_is_on_ && gear_ == Gear::PARKED && speed_ == 0) {
        engine_is_on_ = false;
        return true;
    }
    return false;
}

bool Car::IsSpeedValidForGear(int speed, Gear gear) {
    return speed >= 0 && speed <= GetMaxSpeedForGear(gear);
}

int Car::GetMaxSpeedForGear(Gear gear) {
    switch (gear) {
        case Gear::PARKED:
            return 0;
        case Gear::DRIVE:
            return MAX_SPEED;
        case Gear::REVERSE:
            return MAX_REVERSE_SPEED;
    }
    return 0;
}