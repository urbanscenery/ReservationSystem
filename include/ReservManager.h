#pragma once
#include "ReservList.h"
#include "Member.h"

class ReservManager
{
public:
	ReservManager();
	~ReservManager();
	ReservList* getReservLists(char* guestID, ReservList* allReservList);
	void addNewReservation(char * guestID, Accomm* accomm, ReservList* allReservList);
};