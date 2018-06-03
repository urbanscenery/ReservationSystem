#include "Accomm.h"
#include <iostream>


Accomm::Accomm()
{
}

Accomm::Accomm(char * accommID, char * city, int price, int date, int opqPrice, char* hostID, int currentTime)
{
	strcpy(this -> accommID, accommID);
	strcpy(this -> city, city);
	this -> price = price;
	this -> date = date;
	this -> opqPrice = opqPrice;
	reservationCheck = 0;
	strcpy(this->hostID, hostID);
	accommTimer.setTimer(currentTime);
	next = NULL;
}

Accomm::~Accomm()
{
}

void Accomm::setData(char * accommID, char * city, int price, int date, int opqPrice)
{
	strcpy(this -> accommID, accommID);
	strcpy(this -> city, city);
	this -> price = price;
	this -> date = date;
	this -> opqPrice = opqPrice;
}

void Accomm::setReservationCheck()
{
	reservationCheck = 1;
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

AccommTimer* Accomm::getAccommTimer()
{
	return &accommTimer;
}


