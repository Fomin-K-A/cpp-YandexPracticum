#include <iostream>
#include <string>

void CountAndPrint(std::string str, char character) {
  int count = 0;
  std::size_t pos = str.find(character);
  while (pos != std::string::npos) {
    count++;
    pos = str.find(character, pos + 1);
  }
  std::cout << "В строке \"" << str << "\" символ '" << character
            << "' встречается " << count << " раз(а)." << std::endl;
}

void SplitAndAnalyze(std::string str, char delimiter, char character) {
  std::size_t start = 0;
  std::size_t end = str.find(delimiter);

  while (end != std::string::npos) {
    std::string substring = str.substr(start, end - start);
    CountAndPrint(substring, character);

    start = end + 1;
    end = str.find(delimiter, start);
  }

  std::string substring = str.substr(start);
  CountAndPrint(substring, character);
}

int main() {
  std::string str;
  std::getline(std::cin, str);

  char del;
  std::cin >> del;

  char ch;
  std::cin >> ch;

  SplitAndAnalyze(str, del, ch);
}