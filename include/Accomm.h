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
	char date[MAX_STRING];
	int opqPrice;
	int opqCheck;
	char reservationCheck;
//	Timer accommTimer;
	Accomm* next;

public:
	Accomm();
	Accomm(char * accommID, char* city, int price, char * date, int opqPrice);
	~Accomm();
	char* getAccommDetails();
	void getAccommLists();
	void getReservation();
	
	void setData(char * id, char * ct, int pr, char* dt, int opqPr);//ªË¡¶
	void setOpqPrice(int opqPrice);
	void setOpqCheck();
	void setReservationCheck();
	
	Accomm* getNext();
	void setNext(Accomm* ptr);
};




