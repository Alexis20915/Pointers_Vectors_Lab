#include "Inventory.h"
#include <iostream>

Inventory::~Inventory() {
    for (Book* bookPtr : books) {
        delete bookPtr;
    }
    books.clear();
    std::cout << "Inventory destroyed. All books deallocated." << std::endl;
}

void Inventory::addBook(Book* bookPtr) {
    books.push_back(bookPtr);
    std::cout << "Book added successfully!" << std::endl;
}

void Inventory::displayAll() const {
    if (books.empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    std::cout << "\n=== BOOK INVENTORY ===" << std::endl;
    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << "Book #" << i + 1 << ":" << std::endl;
        books[i]->displayInfo();
    }
}

void Inventory::removeBook(int index) {
    int vectorIndex = index - 1;

    if (vectorIndex < 0 || vectorIndex >= static_cast<int>(books.size())) {
        std::cout << "Invalid index. No book removed." << std::endl;
        return;
    }

    delete books[vectorIndex];
    books.erase(books.begin() + vectorIndex);
    std::cout << "Book #" << index << " removed successfully." << std::endl;
}

int Inventory::getSize() const {
    return static_cast<int>(books.size());
}