#include <iostream>
#include <string>

struct Book {
  std::string title;
  std::string author;  // author типа std::string,
  int publication_year;  // publication_year типа int.
};

int main() {
  Book book;
  // Считываем название книги.
  std::getline(std::cin, book.title);
  std::getline(std::cin, book.author);
  std::cin >> book.publication_year;
  std::cout << book.title << " by " << book.author << " was published in "
            << book.publication_year << "." << std::endl;

  return 0;
}