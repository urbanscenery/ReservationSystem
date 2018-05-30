#include "MyReservationUI.h"

void MyReservationUI::startUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList)
{
	ReservList* myReservList;
	char userID[MAX_STRING];
	strcpy(userID, session->getUserID());
	myReservList = reservManager -> getReservLists(userID, allReservList);
	Reservation* reserv = myReservList -> getHead();
	fprintf(out_fp, "4.4 예약정보 조회\n");
	for(int i = 0, max = myReservList -> getCount(); i < max ; i++){
		fprintf(out_fp, "> %s %s %s %d %d\n", reserv -> getHostID(), reserv -> getAccomm() -> getID(), reserv -> getAccomm() -> getCity(), reserv -> getAccomm() -> getDate(), reserv -> getAccomm() -> getPrice());
		reserv = reserv -> getNext();
	}
}