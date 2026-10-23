#pragma once
// Передача, которую может включить автомобиль.
enum class Gear {
    PARKED,   // Режим парковки.
    DRIVE,    // Режим движения вперёд.
    REVERSE,  // Режим заднего хода.
};

// Направление движения.
enum class Direction {
    FORWARD,   // Вперёд.
    BACKWARD,  // Назад.
    STOPPED,   // Стоит на месте.
};

class Car {
public:
    inline static const int MAX_SPEED = 200;
    inline static const int MAX_REVERSE_SPEED = 30;

    void TurnEngineOn();

    bool TurnEngineOff();

    bool IsEngineOn() const;

    bool SetGear(Gear new_gear);

    Gear GetGear() const;

    int GetSpeed() const;

    bool SetSpeed(int new_speed);

    Direction GetDirection() const;

    static bool IsSpeedValidForGear(int speed, Gear gear);

    static int GetMaxSpeedForGear(Gear gear);

private:
    bool engine_is_on_ = false;
    Gear gear_ = Gear::PARKED;
    int speed_ = 0;
};