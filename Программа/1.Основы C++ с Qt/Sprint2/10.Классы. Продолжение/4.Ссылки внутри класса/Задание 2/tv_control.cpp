#include "tv_control.h"

#include <iostream>
#include <string>

using namespace std::literals;

TVControl::TVControl(TV& tv)
    : tv_(tv)
{}

bool TVControl::ReadAndApplyCommand() const {
    std::string action;
    if (!(std::cin >> action)) {
        std::cout << "Invalid command"s << std::endl;
        return false;
    }

    if (action == "Exit"s) {
        return false;
    } else if (action == "Info"s) {
        Info();
    } else if (action == "TurnOn"s) {
        TurnOn();
    } else if (action == "TurnOff"s) {
        TurnOff();
    } else if (action == "SelectChannel"s) {
        int channel;
        if (!(std::cin >> channel)) {
            std::cout << "Invalid channel"s << std::endl;
            return true;
        }
        SelectChannel(channel);
    } else {
        std::cout << "Unknown command"s << std::endl;
    }
    return true;
}

void TVControl::Info() const {
    if (!tv_.IsTurnedOn()) {
        std::cout << "TV is turned off"s << std::endl;
        return;
    }
    std::cout << "TV is turned on. Channel is "s << tv_.GetCurrentChannel() << std::endl;
}

void TVControl::TurnOn() const {
    tv_.TurnOn();
    std::cout << "Turning on"s << std::endl;
}

void TVControl::TurnOff() const {
    tv_.TurnOff();
    std::cout << "TV is turned off"s << std::endl;
}

void TVControl::SelectChannel(int channel) const {
    if (!tv_.IsTurnedOn()) {
        std::cout << "TV is not turned on"s << std::endl;
        return;
    }
    if (channel < TV::MIN_CHANNEL || channel > TV::MAX_CHANNEL) {
        std::cout << "Invalid channel"s << std::endl;
        return;
    }
    tv_.SelectChannel(channel);
    std::cout << "Channel selected"s << std::endl;
}