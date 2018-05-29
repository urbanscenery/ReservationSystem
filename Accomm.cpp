#include "Accomm.h"
#include <iostream>


Accomm::Accomm()
{
	
}

Accomm::Accomm(char * id, char * ct, int pr, char * dt, int opqPr)
{
	strcpy_s(accommID, sizeof(accommID), id);
	strcpy_s(city, sizeof(city), ct);
	price = pr;
	strcpy_s(date, sizeof(date), dt);
	opqPrice = opqPr;
	reservationCheck = 'X';
}


Accomm::~Accomm()
{
}

char* Accomm::getAccommDetails()
{
	return accommID;		//일단 이름만 가져옴(3.1.숙소등록시 사용됨)
}

void Accomm::getAccommLists()
{
	extern FILE* out_fp;
	//for(int i=0; i < member.accommList->getCount; i++)
	//	accommID = AccommSearchPoint[i].
	fprintf(out_fp, "> %s %s %d %s %c %d \n", accommID, city, price, date, reservationCheck, opqPrice);
}

void Accomm::getReservation()
{
}

void Accomm::setData(char * id, char * ct, int pr, char* dt, int opqPr)
{
	//Linked list에 넣기 위해.. Accomm 노드에 data 삽입하는 함수
	strcpy_s(accommID, sizeof(accommID), id);
	strcpy_s(city, sizeof(city), ct);
	price = pr;
	strcpy_s(date, sizeof(date), dt);
	opqPrice = opqPr;
}

void Accomm::setOpqPrice(int opqPrice)
{
}

void Accomm::setOpqCheck()
{
}

void Accomm::setReservationCheck()
{
}

Accomm * Accomm::getNext()
{
	return next;
}

void Accomm::setNext(Accomm * ptr)
{
	next = ptr;
}
