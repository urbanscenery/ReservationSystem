#include "ReservAccommUI.h"


void ReservAccommUI::startAddReservUI(Member** currentUser, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList)
{
	char hostID[MAX_STRING], accommID[MAX_STRING];
	char userID[MAX_STRING];
	strcpy(userID, (*currentUser)->getUserID());
	fscanf(in_fp, "%s %s", hostID, accommID);
	AccommList *list = allAccommList -> searchAccomm(accommID, 0, 3);
	Accomm* accomm = list -> getHead();
	reservManager -> addNewReservation(userID , accomm, allReservList);
	fprintf(out_fp, "4.2. 숙소예약\n");
	int date = accomm->getDate();
	fprintf(out_fp, "> %s %s %s %d:%d:%d %d\n", accomm->getHostID(), accomm->getID(), accomm->getCity(), date/10000, (date%10000)/100, date%100, accomm->getPrice());
}

void ReservAccommUI::opqReservUI(Member** currentUser, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList, AccommManager* accommManager, Timer* currentTime)
{
	char city[MAX_STRING], date[MAX_STRING];
	char userID[MAX_STRING];
	int targetPrice = 0;
	int successCheck = 0;
	int intDate = 0;
	strcpy(userID, (*currentUser)->getUserID());
	fscanf(in_fp, "%s %s %d", city, date, &targetPrice);
	int currentIntDate = currentTime -> getDate(); 
	int currentIntTime = currentTime -> getTime();
	if((currentIntDate - ((*currentUser) -> getMemberTimer() -> getDate())) > 100){
		(*currentUser) -> getMemberTimer() -> setTimer(currentIntDate, currentIntTime);
	} else{
		fprintf(out_fp, "> Try again in 24 hours\n");
		return;
	}

	intDate = stoiDate(date);
	AccommList* list = accommManager -> getAccommLists(city, intDate, 4, allAccommList);
	Accomm* accomm = list -> getHead();
	fprintf(out_fp, "4.3. Opaque Inventory 예약\n");
	for(int i = 0, max = list -> getCount(); i < max; i++){
		if(accomm -> getOpqPrice() <= targetPrice){
			reservManager -> addNewReservation(userID, accomm, allReservList);
			successCheck = 1;
			break;
		}
		accomm = accomm -> getNext();
	}
	if(successCheck){
		intDate = accomm->getDate();
		fprintf(out_fp, "> Success %s %s %s %s %d\n",accomm->getHostID(), accomm->getID(), accomm->getCity(), itoaDate(intDate), accomm->getOpqPrice());
	}else{
		fprintf(out_fp, "> Try again in 24 hours\n");
	}
}