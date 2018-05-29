#include <Reservation.h>

Reservation::Reservation()
{
}

Reservation::Reservation(char* hostID, char* guestID, Accomm* accomm)
{
	strcpy(this->hostID, hostID);
	strcpy(this->guestID, guestID);
	this->accomm = accomm;
	next = NULL;
}

Reservation::~Reservation()
{
}

char* Reservation::getHostID()
{
	return hostID;
}
char* Reservation::getGuestID()
{
	return guestID;
}
Accomm* Reservation::getAccomm()
{
	return accomm;
}
	
Reservation* Reservation::getNext()
{
	return next;
}
void Reservation::setNext(Reservation* ptr)
{
	next = ptr;
}