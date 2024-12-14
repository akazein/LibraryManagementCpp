#pragma once
#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include <fstream>
#include "Book.h"
// File name constant
#define FILE_NAME "books.txt"

// Basic File Operations
bool overwriteFile(const char data[]);               // Overwrite the entire file
bool appendToFile(std::string dataStr);              // Append data to the file
std::string readTextFromFile();                      // Read the entire file into a string

// Higher-Level File Operations
bool saveBooksArrToFile(std::vector<Book> arrBooksObj);  // Save an array of books to file
bool addBookToFile(Book book);                   // Save a single book to the file
std::vector<Book> getArrBooksObjFromFile();             // Retrieve an array of books from the file


#endif // FILEOPERATIONS_H

 