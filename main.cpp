#include <iostream>
#include <limits>
#include "Inventory.h"

void displayMenu();
std::string getStringInput(const std::string& prompt);
double getDoubleInput(const std::string& prompt);
int getIntInput(const std::string& prompt);

int main() {
    Inventory store;
    int choice = 0;

    do {
        displayMenu();
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: {
                std::string title = getStringInput("Enter book title: ");
                std::string author = getStringInput("Enter book author: ");
                double price = getDoubleInput("Enter book price: $");

                Book* newBook = new Book(title, author, price);
                store.addBook(newBook);
                break;
            }

            case 2:
                store.displayAll();
                break;

            case 3: {
                if (store.getSize() == 0) {
                    std::cout << "Inventory is empty. Nothing to remove." << std::endl;
                    break;
                }

                store.displayAll();
                int index = getIntInput("Enter the book number to remove: ");
                store.removeBook(index);
                break;
            }

            case 4:
                std::cout << "Exiting program." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    std::cout << "\n=== MENU ===" << std::endl;
    std::cout << "1. Add New Book" << std::endl;
    std::cout << "2. Display All Books" << std::endl;
    std::cout << "3. Remove Book" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

std::string getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin >> std::ws, input);
    return input;
}

double getDoubleInput(const std::string& prompt) {
    double input;
    std::cout << prompt;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

int getIntInput(const std::string& prompt) {
    int input;
    std::cout << prompt;
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}