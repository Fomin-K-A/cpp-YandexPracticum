#include <cassert>
#include <iostream>
#include <string>

const int MIN_BASE = 2;
const int MAX_BASE = 36;

// Переводит цифру из числового представления в символьное.
char DigitToChar(int digit) {
  if (digit < 0 || digit >= MAX_BASE) {
    return '?';
  }
  return static_cast<char>(digit <= 9 ? '0' + digit : (digit - 10) + 'A');
}

// Преобразует число number в строковое представление
// в системе счисления по основанию base.
// Возвращает пустую строку, если base вне диапазона [2, 36].
std::string NumberToString(int number, int base) {
  if (base < MIN_BASE || base > MAX_BASE) {
    return "";
  }

  std::string str;
  do {
    int digit = number % base;
    str = DigitToChar(digit) + str;
    number = number / base;
  } while (number != 0);

  return str;
}

// Возвращает числовое значение символа или -1, если символ не является цифрой.
int CharToDigit(char ch) {
  if (ch >= '0' && ch <= '9') {
    return ch - '0';
  } else if (ch >= 'A' && ch <= 'Z') {
    return ch - 'A' + 10;
  } else if (ch >= 'a' && ch <= 'z') {
    return ch - 'a' + 10;
  } else {
    return -1;
  }
}

// Преобразует строку s в число в системе счисления base.
// Устанавливает was_error = true при ошибке.
int StringToNumber(const std::string& s, int base, bool& was_error) {
  was_error = false;

  if (base < MIN_BASE || base > MAX_BASE) {
    was_error = true;
    return 0;
  }

  int result = 0;
  int tmp_base = 1;

  for (int i = s.size() - 1; i >= 0; i--) {
    int digit = CharToDigit(s[i]);
    if (digit == -1 || digit >= base) {
      was_error = true;
      return 0;
    }
    result = result + digit * tmp_base;
    tmp_base = tmp_base * base;
  }

  return result;
}

// Преобразует число из одной системы счисления в другую.
// Возвращает пустую строку при ошибке.
std::string ConvertNotation(const std::string& src_number, int src_base,
                            int dst_base) {
  bool was_error = false;
  int number_dec = StringToNumber(src_number, src_base, was_error);
  if (was_error) {
    return "";
  }

  std::string result = NumberToString(number_dec, dst_base);
  if (result.empty()) {
    return "";
  }

  return result;
}

int main() {
  using namespace std::literals;
  std::string src_string;
  int src_base, dst_base;

  std::cin >> src_string >> src_base >> dst_base;

  if (auto result = ConvertNotation(src_string, src_base, dst_base);
      !result.empty()) {
    std::cout << result << std::endl;
  } else {
    std::cout << "ERROR"s << std::endl;
  }
}