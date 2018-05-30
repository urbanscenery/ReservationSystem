#include "Accomm.h"
#include <iostream>


Accomm::Accomm()
{
}

Accomm::Accomm(char * id, char * ct, int pr, int dt, int opqPr)
{
	strcpy(accommID, id);
	strcpy(city, ct);
	price = pr;
	date = dt;
	opqPrice = opqPr;
	reservationCheck = 'X';
	next = NULL;
}


Accomm::~Accomm()
{
}

void Accomm::getAccommLists()
{
}

void Accomm::getReservation()
{
}

void Accomm::setData(char * id, char * ct, int pr, int dt, int opqPr)
{
	strcpy(accommID, id);
	strcpy(city, ct);
	price = pr;
	date = dt;
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

char* Accomm::getID()
{
	return accommID;
}

char* Accomm::getCity()
{
	return city;
}

int Accomm::getDate()
{
	return date;
}

int Accomm::getPrice()
{
	return price;
}

int Accomm::getOpqPrice()
{
	return opqPrice;
}

char* Accomm::getHostID()
{
	return hostID;
}


