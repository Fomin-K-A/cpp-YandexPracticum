#include <cassert>
#include <iostream>
#include <string>

class Time {
public:
    // Количество часов в сутках.
    inline static const int HOURS_PER_DAY = 24;
    // Количество минут в часе.
    inline static const int MINUTES_PER_HOUR = 60;
    // Количество секунд в минуте.
    inline static const int SECONDS_PER_MINUTE = 60;
    // Количество секунд в часе.
    inline static const int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
    // Количество секунд в сутках.
    inline static const int SECONDS_PER_DAY = SECONDS_PER_HOUR * HOURS_PER_DAY;

    // Изменяет текущее значение времени.
    void SetTime(int hours, int minutes, int seconds) {
        time_offset_ = hours * SECONDS_PER_HOUR + minutes * SECONDS_PER_MINUTE + seconds;
    }

    // Возвращает количество секунд (от 0 до 59).
    int GetSeconds() const {
        return time_offset_ % SECONDS_PER_MINUTE;
    }

    // Возвращает количество минут (от 0 до 59).
    int GetMinutes() const {
        // time_offset_ / SECONDS_PER_MINUTE — это количество минут, прошедших с начала суток.
        // Взяв остаток от деления этого числа на 60, получим количество минут,
        // прошедших с начала текущего часа.
        return (time_offset_ / SECONDS_PER_MINUTE) % MINUTES_PER_HOUR;
    }

    // Возвращает количество часов (от 0 до 23).
    int GetHours() const {
        return time_offset_ / SECONDS_PER_HOUR;
    }

    // Возвращает разницу между временами to и from в секундах.
    // Предполагается, что оба момента происходят в одни сутки.
    // Текущее время не изменяется.
    static int GetDistance(Time from, Time to) {
        return to.time_offset_ - from.time_offset_;
    }

    // Увеличивает текущее время на заданное количество секунд.
    // Величина offset может быть положительной, отрицательной или нулём.
    void AddSeconds(int offset) {
        // Используем трюк (x % N + N) % N.
        int new_time = (time_offset_ + offset) % SECONDS_PER_DAY;
        time_offset_ = (new_time + SECONDS_PER_DAY) % SECONDS_PER_DAY;
    }

private:
    // Количество секунд, прошедших с начала суток.
    int time_offset_ = 0;
};

using namespace std::literals;

std::string MakeTwoDigitNumber(int n) {
    auto s = std::to_string(n);
    return n < 10 ? "0"s + s : s;
}

std::string ToString(Time t) {
    return MakeTwoDigitNumber(t.GetHours()) + ":"s + MakeTwoDigitNumber(t.GetMinutes()) + ":"s
        + MakeTwoDigitNumber(t.GetSeconds());
}

int main() {
    Time t, t1, t2;

    // По умолчанию время равно 00:00:00.
    assert((t.GetHours() == 0) && (t.GetMinutes() == 0) && (t.GetSeconds() == 0));

    t.SetTime(23, 59, 40);
    t.AddSeconds(25);
    assert(ToString(t) == "00:00:05"s);

    t.SetTime(0, 15, 10);
    t.AddSeconds(-911);
    assert(ToString(t) == "23:59:59"s);

    t.SetTime(23, 59, 59);
    assert(ToString(t) == "23:59:59"s);
    t.SetTime(0, 0, 0);
    assert(ToString(t) == "00:00:00"s);

    t.AddSeconds(59);
    assert((ToString(t) == "00:00:59"s));

    t.AddSeconds(3);
    assert((ToString(t) == "00:01:02"s));

    t.AddSeconds(59 * Time::SECONDS_PER_MINUTE);
    assert((ToString(t) == "01:00:02"s));

    t.SetTime(23, 59, 59);
    t.AddSeconds(Time::SECONDS_PER_HOUR + Time::SECONDS_PER_MINUTE + 1);
    assert((ToString(t) == "01:01:00"s));

    t.AddSeconds(-(Time::SECONDS_PER_HOUR + Time::SECONDS_PER_MINUTE + 1));
    assert((ToString(t) == "23:59:59"s));

    t.AddSeconds(30 * Time::SECONDS_PER_HOUR);
    assert((ToString(t) == "05:59:59"s));

    t1.SetTime(6, 1, 1);

    assert(Time::GetDistance(t, t1) == 62);
    assert(Time::GetDistance(t1, t) == -62);

    t1.SetTime(7, 40, 0);
    t2.SetTime(12, 0, 0);
    assert(Time::GetDistance(t1, t2) == 15600);

    t1.SetTime(7, 40, 0);
    t2.SetTime(12, 0, 0);
    assert(Time::GetDistance(t2, t1) == -15600);

    std::cout << "Program testing OK"s << std::endl;
}