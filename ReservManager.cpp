#include "ReservManager.h"

ReservManager::ReservManager()
{

}
ReservManager::~ReservManager()
{

}
ReservList* ReservManager::getReservLists(char* guestID, ReservList* allReservList)
{
	allReservList -> displayReservList();
	ReservList* list = allReservList -> searchReservation(guestID);
	return list;
}
void ReservManager::addNewReservation(char * guestID, Accomm* accomm, ReservList* allReservList)
{
	allReservList -> insertNode(guestID, accomm);
}