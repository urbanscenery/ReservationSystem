#pragma once
#include "Accomm.h"

class AccommList
{
private:
	Accomm* head;
	Accomm* tail;
	int count;
	bool searchMethodCheck(char* index1, int date, Accomm* accomm, int method);
	bool alignMethodCheck(Accomm* accomm, int method);


public:
	AccommList();
	~AccommList();
	int getCount();
	Accomm* getHead();
	void insertNode(char * accommID, char* city, int price, int date, int opqPrice,  char* hostID, int currentTime);
	void deleteNode();
	void displayAccommList();
	AccommList* searchAccomm(char* index1, int date, int searchMethod);
	void alignAccommList(int alignMethod);
};

