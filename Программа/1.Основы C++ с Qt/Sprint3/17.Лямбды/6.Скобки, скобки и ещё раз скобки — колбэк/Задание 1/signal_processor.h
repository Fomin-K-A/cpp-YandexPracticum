#pragma once

#include <format>
#include "universe_listener.h"
#include "email_sender.h"

inline std::string GetAddressByType(UniverseSignalType type) {
    using namespace std::literals;
    switch (type) {
    case UniverseSignalType::UFO:
        return "ufo@secret-committee.gov"s;
    case UniverseSignalType::SUPERNOVA:
        return "evacuation@transport-department.gov"s;
    case UniverseSignalType::DYSON_SPHERE:
        return "alien-contacts@secret-committee.gov"s;
    case UniverseSignalType::GRAVITATIONAL_LENS:
        return "astronomy@university.edu"s;
    }
    abort();
}

class SignalProcessor {
public:
    explicit SignalProcessor(UniverseListener& listener, EmailSender& sender) {
        static constexpr double threshold = 0.8;

        auto callback = [&]<UniverseSignalType type>(const UniverseSignal<type>&signal) {
            if (signal.info.signal_strength < threshold) {
                return;
            }

            const auto subject = "Обнаружен объект: " + signal.payload.name;
            const auto body = std::format(
                "В области неба {};{} обнаружен указанный объект. Сила сигнала: {}.",
                signal.info.coordinates.ra,
                signal.info.coordinates.dec,
                signal.info.signal_strength);

            sender.Send(subject, body, GetAddressByType(type), signal.payload);
        };

        listener.SetCallbackUfo(callback);
        listener.SetCallbackSupernova(callback);
        listener.SetCallbackDysonSphere(callback);
        listener.SetCallbackGravitationalLens(callback);
    }
};
