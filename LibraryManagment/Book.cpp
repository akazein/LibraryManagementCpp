#include "Book.h"




Book::Book(std::string title, std::string description, std::string whoBorrowed, int daysLeft) {
	this->title = title;
	this->description = description;
	this->whoBorrowed = whoBorrowed;
	this->daysLeft = daysLeft;
}

Book::Book(){}

std::string Book::getTitle()
{
	return this->title;
}

std::string Book::getDescription() {
	return this->description;
}


std::string Book::getWhoBorrowed() {
	return this->whoBorrowed;
}

int Book::getDaysLeft() {
	return this->daysLeft;
}

std::string Book::serialize() {
	return "#"+ title + "|" + description + "|" + whoBorrowed + "|" + std::to_string(daysLeft);
}


Book Book::deSerialize(const std::string& data) {
	size_t pos1 = data.find('|');
	size_t pos2 = data.find('|', pos1 + 1);
	size_t pos3 = data.find('|', pos2 + 1);

	std::string title = data.substr(0, pos1);
	std::string description = data.substr(pos1 + 1, pos2 - pos1 - 1);
	std::string whoBorrowed = data.substr(pos2 + 1, pos3 - pos2 - 1);
	int daysLeft = std::stoi(data.substr(pos3 + 1));

	return Book(title, description, whoBorrowed, daysLeft);
}

void Book::toString() {
	std::cout << "Title: " << this->title << "\n"
		<< "Description: " << this->description << "\n"
		<< "Who Borrowed: " << (this->whoBorrowed.empty() ? "None" : this->whoBorrowed) << "\n"
		<< "Days Left: " << (this->daysLeft > 0 ? std::to_string(this->daysLeft) : "Not borrowed") << "\n";
}


