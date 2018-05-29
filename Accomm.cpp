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
	return accommID;		//�ϴ� �̸��� ������(3.1.���ҵ�Ͻ� ����)
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
	//Linked list�� �ֱ� ����.. Accomm ��忡 data �����ϴ� �Լ�
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
