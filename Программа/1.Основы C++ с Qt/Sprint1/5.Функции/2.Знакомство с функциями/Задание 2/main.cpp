#include <iostream>
#include <string>

void CountAndPrint(std::string str,char ch) {
  int counter = 0;
  size_t pos = 0;
  while (true) {
    pos = str.find(ch, pos);
    if (pos == std::string::npos) {
      break;
    }
    counter++;
    pos++;
  }
  std::cout << "В строке \"" << str << "\" символ '" << ch << "' встречается "
            << counter << " раз(а).\n";
}

int main() {
  std::string str;
  std::getline(std::cin, str);

  char ch;
  std::cin >> ch;

  CountAndPrint(str, ch);
}