#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    Book(const std::string& t, const std::string& a, double p)
        : title(t), author(a), price(p) {}

    void displayInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

#endif