#pragma once
#include <cstring>
#include <iostream>
#include "AccommTimer.h"

#define MAX_STRING 32

using namespace std;

class Accomm
{

private:
	char accommID[MAX_STRING];
	char city[MAX_STRING];
	char hostID[MAX_STRING];
	int price;
	int date;
	int opqPrice;
	int opqCheck;
	bool reservationCheck;
	Accomm* next;
	AccommTimer accommTimer;

public:
	Accomm();
	Accomm(char * accommID, char* city, int price, int date, int opqPrice, char * hostID, int currentTime);
	~Accomm();
	char* getID();
	char* getCity();
	char* getHostID();
	int getDate();
	int getPrice();
	int getOpqPrice();
	Accomm* getNext();
	AccommTimer* getAccommTimer();
	
	void setData(char * id, char * ct, int pr, int dt, int opqPr);
	void setReservationCheck();
	void setNext(Accomm* ptr);
};




