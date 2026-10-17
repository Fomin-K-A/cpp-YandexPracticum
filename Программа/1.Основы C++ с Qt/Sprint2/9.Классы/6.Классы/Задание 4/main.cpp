#include <cassert>  // Включаем для запуска юнит-тестов.
#include <iostream>

const int MIN_CHANNEL = 1;
const int MAX_CHANNEL = 99;

class TV {
 public:
  void TurnOn() { is_turned_on_ = true; }

  void TurnOff() { is_turned_on_ = false; }

  bool IsTurnedOn() { return is_turned_on_; }

  int GetCurrentChannel() {
    if (!is_turned_on_) return 0;
    return channel_;
  }

  bool SelectChannel(int ch) {
    if (!is_turned_on_) {
      return false;
    }
    if (ch < MIN_CHANNEL || ch > MAX_CHANNEL) {
      return false;
    }
    channel_ = ch;
    return true;
  }

 private:
  bool is_turned_on_ = false;
  int channel_ = 1;
};

int main() {
  {
    TV tv;
    assert(!tv.IsTurnedOn());
  }
  {
    TV tv;
    assert(!tv.IsTurnedOn());
    tv.TurnOn();
    assert(tv.IsTurnedOn());
    tv.TurnOff();
    assert(!tv.IsTurnedOn());
  }
  {
    TV tv;
    assert(!tv.IsTurnedOn());
    assert(tv.GetCurrentChannel() == 0);
    tv.TurnOn();
    assert(tv.GetCurrentChannel() == 1);
    tv.TurnOff();
    assert(tv.GetCurrentChannel() == 0);
  }
  {
    TV tv;
    tv.TurnOn();
    for (auto i = 0; i < 10; ++i) {
      int channel = (71 * i) % MAX_CHANNEL + 1;
      assert(tv.SelectChannel(channel));
      assert(tv.GetCurrentChannel() == channel);
    }
  }
  {
    TV tv;
    tv.TurnOff();
    int channel = 50;
    assert(!tv.SelectChannel(channel));
    assert(tv.GetCurrentChannel() == 0);
  }
  {
    TV tv;
    tv.TurnOn();
    for (auto i = 0; i < 10; ++i) {
      int channel = (641 * i) % MAX_CHANNEL + 1;
      assert(tv.SelectChannel(channel));
      assert(tv.GetCurrentChannel() == channel);
      tv.TurnOff();
      assert(!tv.IsTurnedOn());
      assert(tv.GetCurrentChannel() == 0);
      tv.TurnOn();
      assert(tv.GetCurrentChannel() == channel);
    }
  }
  std::cout << "Program testing OK" << std::endl;
}