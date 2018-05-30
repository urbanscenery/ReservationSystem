#pragma once
#include "Reservation.h"
#include "ReservList.h"
#include "Accomm.h"
#include <iostream>

class ReservManager
{
public:
	ReservManager();
	~ReservManager();
	ReservList* getReservLists(char* guestID, ReservList* allReservList);
	void addNewReservation(char * guestID, Accomm* accomm, ReservList* allReservList);
};