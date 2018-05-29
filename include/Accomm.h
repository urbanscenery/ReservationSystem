#pragma once
#include <string>
using namespace std;
#define MAX_STRING 32

class Accomm
{

private:
	char accommID[MAX_STRING];
	char city[MAX_STRING];
	//string subaddress[MAX_STRING];
	//int bedCount;
	//int bathCount;
	int price;
	int date;
	int opqPrice;
	int opqCheck;
	char reservationCheck;
//	Timer accommTimer;
	Accomm* next;

public:
	Accomm();
	Accomm(char * accommID, char* city, int price, int date, int opqPrice);
	~Accomm();
	char* getAccommDetails();
	void getAccommLists();
	void getReservation();
	char* getID();
	char* getCity();
	int getDate();
	int getPrice();
	int getOpqPrice();
	
	void setData(char * id, char * ct, int pr, int dt, int opqPr);//ªË¡¶
	void setOpqPrice(int opqPrice);
	void setOpqCheck();
	void setReservationCheck();
	
	Accomm* getNext();
	void setNext(Accomm* ptr);
};




