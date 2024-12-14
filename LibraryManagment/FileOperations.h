#pragma once
#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include <fstream>
#include "Book.h"
// Declare the saveFile function
/*bool saveFile();
bool readFile();*/

bool appendFile(const char data[]);
//bool readFile();
bool saveBooksToFile(std::vector<Book> arrBooksObj);
std::string readTextFromFile();
#endif // FILEOPERATIONS_H

 