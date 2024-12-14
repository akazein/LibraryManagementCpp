
#include "FileOperations.h"
#include "Book.h"

//BASIC FILE OPERATIONS

bool overwriteFile(const char data[]) {
	std::ofstream os(FILE_NAME);
    int length = std::strlen(data);
	if (os.is_open()) {
		os.write(data, length);
        os.close();
		return true;
    }
    
    return false;
    
}


bool appendToFile(std::string dataStr) {
    const char *data = dataStr.c_str();
    std::ofstream os(FILE_NAME, std::ios::app);
    int length = std::strlen(data);
    if (os.is_open()) {
        os.write(data, length);
        os.close();
        return true;
    }

    return false;

}


std::string readTextFromFile() {
    Book book;
    std::string fileText;
    std::ifstream is(FILE_NAME);

    if (!is.is_open()) {
        std::cerr << "Error: Unable to open file for reading.\n";
    }

    if (is.is_open()) {
        is.seekg(0, std::ios::end);
        fileText.reserve(is.tellg());
        is.seekg(0, std::ios::beg);
        fileText.assign(std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>());
        is.close();
    }

    return fileText;
}





//FUNCTIONS THAT CALL BASIC FILE OPERATIONS

bool saveBooksArrToFile(std::vector<Book> arrBooksObj) {
    const int arrBooksObjSize = arrBooksObj.size();
    std::string booksStr ="";
    int i = 0;
    for (i = 0; i < arrBooksObj.size(); i++) {
        booksStr += arrBooksObj[i].serialize();
    }
    booksStr += "\n";
    const char* charArray = booksStr.c_str();

    return overwriteFile(charArray);


    
}


bool addBookToFile(Book book) {
    std::string serializedBook = book.serialize();
    return appendToFile(serializedBook);
}


std::vector<Book> getArrBooksObjFromFile() {
    Book book;
    size_t posBreakChar;
    int i = 0;
    std::string subStringTextFile;
    std::vector<Book> arrBooks;
    std::string textFile = readTextFromFile();
    int bookAmount = std::count(textFile.begin(), textFile.end(), '#');

    for (i = 0; i < bookAmount; i++) {
        textFile.erase(0, 1);
        posBreakChar = textFile.find_first_of('#');
        subStringTextFile = textFile.substr(0, posBreakChar);
        textFile.erase(0, posBreakChar);
        book = Book::deSerialize(subStringTextFile);
        arrBooks.push_back(book);
    }
    return arrBooks;
}
