#pragma once
#include <string>
#include <chrono>
using namespace std;


class Book
{
public:
	string title;
	string description;
	bool isTaken=NULL;
	string whoBorrowed = NULL;
	//int daysLeft=NULL;

	Book(string title, string description, bool isTaken, string whoBorrowed, int daysLeft) {
		this->title= title;
		this->description = description;
		this->isTaken = isTaken;
		this->whoBorrowed = whoBorrowed;
		//this->daysLeft = daysLeft;
	}

	string getTitle()
	{
		return this->title;
	}

	string getDescription() {
		return this->description;
	}

	bool isTaken() {
		return this->isTaken;
	}

	string whoBorrowed() {
		return this->whoBorrowed;
	}

	/*int getDaysLeft() {
		return this->daysLeft;
	}*/

};

