#include "ReservList.h"
#include<iostream>

ReservList::ReservList()
{
	head = new Reservation();
	tail = head;
	count = 0;
}

ReservList::~ReservList()
{
	
}

int ReservList::getCount()
{
	return count;
}

Reservation* ReservList::getHead() 
{
	return head->getNext();
}

void ReservList::insertNode(char* guestID, Accomm* accomm)
{
	Reservation* newReservation = new Reservation(accomm->getHostID(), guestID, accomm);
	tail -> setNext(newReservation);
	tail = newReservation;
	count++;
}
void ReservList::deleteNode()
{

}
void ReservList::displayReservList()
{
	Reservation* temp = head->getNext();
	for(int i = 0 ; i < count ; i++){
		temp = temp->getNext();
	}
}
ReservList* ReservList::searchReservation(char* guestID)
{
	ReservList* list = new ReservList();
	Reservation* reservation = this -> getHead();
	for(int i = 0, max = this -> getCount() ; i < max ; i++){
		if(!strcmp(reservation->getGuestID(), guestID)){
			list -> insertNode(reservation->getGuestID(), reservation -> getAccomm());
		}
		reservation = reservation -> getNext();
	}
	return list;
}
