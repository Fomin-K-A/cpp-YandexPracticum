#pragma once

const int MIN_CHANNEL = 1;
const int MAX_CHANNEL = 99;

class TV {
public:
    void TurnOn();
    void TurnOff();
    bool IsTurnedOn();
    int GetCurrentChannel();
    bool SelectChannel(int channel);

private:
    bool is_turned_on_ = false;
    int current_channel_ = 1;
};