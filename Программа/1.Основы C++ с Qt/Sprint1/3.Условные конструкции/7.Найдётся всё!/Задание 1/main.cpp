#include <iostream>
#include <string>

int main() {
  std::string haystack, needle, replacement;
  std::getline(std::cin, haystack);
  std::getline(std::cin, needle);
  std::getline(std::cin, replacement);

  int needle_size = needle.size();
  std::size_t pointer = haystack.find(needle);

  std::string tmp1;
  std::string tmp2;

  if (pointer != std::string::npos) {
    tmp1 = haystack.substr(0, pointer);
    tmp2 = haystack.substr(pointer + needle_size);
    haystack = tmp1 + replacement + tmp2;
  }
  

  std::cout << haystack << std::endl;
}