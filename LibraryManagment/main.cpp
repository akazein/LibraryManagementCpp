
#include "Book.h"
#include "FileOperations.h"
#include "Header.h"


int main() {
	
	std::vector<Book> arrBooks;
	int i = 0;
	Book book;
	for (i = 0; i < 10; i++) {
		book = Book("title" + std::to_string(i), "desc" + std::to_string(i), "whoborrowed" + std::to_string(i), i);
		arrBooks.push_back(book);

	}
	book = Book();

	saveBooksToFile(arrBooks);

	arrBooks.clear();

	std::string textFile = readTextFromFile();
	int bookAmount = std::count(textFile.begin(), textFile.end(), '#');


	std::cout << std::to_string(bookAmount) + "\n";

	size_t posBreakChar;
	std::string subStringTextFile;


	for (i = 0; i < bookAmount; i++) {
		textFile.erase(0,1);
		posBreakChar = textFile.find_first_of('#');
		subStringTextFile = textFile.substr(0, posBreakChar);
		textFile.erase(0, posBreakChar);
		book = Book::deSerialize(subStringTextFile);
		arrBooks.push_back(book);
	}




	for (i = 0; i < arrBooks.size(); i++) {
		arrBooks[i].toString();
		
	}




	//std::cout << readFile() + "\n";

	return 0;
}