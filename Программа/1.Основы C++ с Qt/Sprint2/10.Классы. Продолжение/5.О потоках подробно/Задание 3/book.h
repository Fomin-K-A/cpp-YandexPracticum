#pragma once

#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int publication_year = 0;
};

void WriteBook(std::ostream& out, const Book& book);
Book ReadBook(std::istream& in);
std::string BookToString(const Book& book);
Book StringToBook(const std::string& str);
void SaveBookToFile(const std::string& file_name, const Book& book);
Book LoadBookFromFile(const std::string& file_name);