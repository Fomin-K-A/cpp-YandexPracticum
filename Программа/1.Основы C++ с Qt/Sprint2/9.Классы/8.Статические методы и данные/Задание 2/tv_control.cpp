#include "tv_control.h"

#include <iostream>
#include <string>

using namespace std::literals;

bool TVControl::ReadAndApplyCommand(TV& tv) {
    std::string action;

    if (!(std::cin >> action)) {
        std::cout << "Invalid command"s << std::endl;
        return false;
    }

    if (action == "Exit"s) {
        return false;
    } else if (action == "Info"s) {
        Info(tv);
    } else if (action == "TurnOn"s) {
        TurnOn(tv);
    } else if (action == "TurnOff"s) {
        TurnOff(tv);
    } else if (action == "SelectChannel"s) {
        SelectChannel(tv);
    } else {
        std::cout << "Unknown command"s << std::endl;
    }
    return true;
}

void TVControl::Info(TV& tv) {
    if (!tv.IsTurnedOn()) {
        std::cout << "TV is turned off"s << std::endl;
    } else {
        std::cout << "TV is turned on. Channel is "s
                  << tv.GetCurrentChannel() << std::endl;
    }
}

void TVControl::TurnOn(TV& tv) {
    tv.TurnOn();
    std::cout << "Turning on"s << std::endl;
}

void TVControl::TurnOff(TV& tv) {
    tv.TurnOff();
    std::cout << "TV is turned off"s << std::endl;
}

void TVControl::SelectChannel(TV& tv) {
    int channel;
    std::cin >> channel;

    if (!tv.IsTurnedOn()) {
        std::cout << "TV is not turned on"s << std::endl;
    } else if (!tv.SelectChannel(channel)) {
        std::cout << "Invalid channel"s << std::endl;
    } else {
        std::cout << "Channel selected"s << std::endl;
    }
}