
#include "FileOperations.h"
#include "Book.h"

bool appendFile(const char gino[]) {
	std::ofstream os(FILE_NAME);
    int length = std::strlen(gino);
	if (os.is_open()) {
		os.write(gino, length);
        os.close();
		return true;
    }
    
    return false;
    
}
/*

bool readFile() {
    std::ifstream os(FILE_NAME);
    if (os.is_open()) {
        std::string fileText;
        os.seekg(0, std::ios::end);
        fileText.reserve(os.tellg());
        os.seekg(0, std::ios::beg);
        fileText.assign(std::istreambuf_iterator<char>(os),
        std::istreambuf_iterator<char>());
        std::cout << fileText + "\n";
        os.close(); 
        return true;
    }

    std::cerr << "Error: can't open file\n";
    return false;
}


*/

bool saveBooksToFile(std::vector<Book> arrBooksObj) {
    const int arrBooksObjSize = arrBooksObj.size();
    std::string booksStr ="";
    int i = 0;
    for (i = 0; i < arrBooksObj.size(); i++) {
        booksStr += arrBooksObj[i].serialize();
    }
    booksStr += "\n";
    const char* charArray = booksStr.c_str();

    return appendFile(charArray);


    
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


