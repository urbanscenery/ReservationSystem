#pragma once
#include "Accomm.h"

class AccommList
{
private:
	Accomm* head;
	Accomm* tail;
	int count;

public:
	AccommList();
	~AccommList();
	int getCount();
	Accomm* getHead();
	void insertNode(char * accommID, char* city, int price, char* date, int opqPrice);
	void deleteNode();
	void displayAccommList();
};

