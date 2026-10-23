#include "string_utils.h"

std::vector<size_t> FindString(const std::string& text,
                               const std::string& text_to_find) {
  std::vector<size_t> result;

  if (text_to_find.empty()) {
    return result;
  }

  size_t pos = 0;
  while ((pos = text.find(text_to_find, pos)) != std::string::npos) {
    result.push_back(pos);
    pos++;  
  }

  return result;
}