#ifndef BOOK_H
#define BOOK_H

#include "Header.h"

class Book {
public:
    // Member variables
    std::string title;
    std::string description;
    std::string whoBorrowed;
    int daysLeft;

    // Constructors
    Book(std::string title, std::string description, std::string whoBorrowed, int daysLeft);
    Book();

    // Getter methods
    std::string getTitle();
    std::string getDescription();
    std::string getWhoBorrowed();
    int getDaysLeft();
    std::string serialize();
    Book static deSerialize(const std::string& data);
    // Method to print the book details
    void toString();
};

#endif // BOOK_H
