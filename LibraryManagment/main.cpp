
#include "Book.h"
#include "FileOperations.h"
#include "Header.h"


std::vector<Book> populateBooksArr() {
	std::vector<Book> arrBooks;
	std::string titlePrefixes[] = { "The Adventures of", "Mystery of", "Chronicles of", "The Legend of", "Tales from" };
	std::string titleSubjects[] = { "the Lost City", "the Brave Warrior", "the Hidden Treasure", "the Haunted Castle", "the Wise Sage" };
	std::string descThemes[] = { "A thrilling journey.", "A spine-chilling mystery.", "An epic saga.", "A heartwarming tale.", "A fascinating exploration." };
	std::string borrowedNames[] = { "Alice", "Bob", "Charlie", "Diana", "Ethan", "Fiona", "George", "Hannah", "Ian", "Julia" };

	for (int i = 0; i < 10; i++) {
		// Generate random indices for creative fields
		int titlePrefixIndex = i % 5; // Cycle through prefixes
		int titleSubjectIndex = (i + 2) % 5; // Offset for variety
		int descThemeIndex = (i + 3) % 5; // Another offset
		int borrowerIndex = i % 10; // Cycle through borrower names

		// Construct book details
		std::string title = titlePrefixes[titlePrefixIndex] + " " + titleSubjects[titleSubjectIndex];
		std::string description = descThemes[descThemeIndex];
		std::string borrowedBy = borrowedNames[borrowerIndex];

		// Create a Book object and add it to the vector
		Book book(title, description, borrowedBy, i);
		arrBooks.push_back(book);
	}
	return arrBooks;
}

void printAllBooks(std::vector<Book> arrBooks) {
	int i = 0;
	for (i = 0; i < arrBooks.size(); i++) {
		arrBooks[i].toString();
		std::cout << "\n\n";

	}
}

int main() {
	
	std::vector<Book> arrBooks;
	int i = 0;
	


	arrBooks = populateBooksArr();

	arrBooks.clear();

	arrBooks = getArrBooksObjFromFile();

	printAllBooks(arrBooks);

	

	std::cin.get();
	return 0;
}