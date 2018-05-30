#pragma once
#include <string>
using namespace std;
#define MAX_STRING 32

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
	char reservationCheck;
	Accomm* next;

public:
	Accomm();
	Accomm(char * accommID, char* city, int price, int date, int opqPrice);
	~Accomm();
	void getAccommLists();
	void getReservation();
	char* getID();
	char* getCity();
	char* getHostID();
	int getDate();
	int getPrice();
	int getOpqPrice();
	
	void setData(char * id, char * ct, int pr, int dt, int opqPr);
	void setOpqPrice(int opqPrice);
	void setOpqCheck();
	void setReservationCheck();
	
	Accomm* getNext();
	void setNext(Accomm* ptr);
};




