#pragma once
#include "Accomm.h"
#include <string.h>

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
	void insertNode(char * accommID, char* city, int price, int date, int opqPrice);
	void deleteNode();
	void displayAccommList();
	AccommList* searchAccomm(char* city, int date);
	void alignAccommList(int alignMethod);
};

