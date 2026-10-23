#pragma once
#include "tv.h"

class TVControl {
public:
    TVControl(TV& tv);

    bool ReadAndApplyCommand() const;

private:
    TV& tv_;

private:
    void Info() const;
    void TurnOn() const;
    void TurnOff() const;
    void SelectChannel(int channel) const;
};