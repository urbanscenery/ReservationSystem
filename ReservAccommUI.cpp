#include "ReservAccommUI.h"


void ReservAccommUI::startAddReservUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList)
{
	char hostID[MAX_STRING], accommID[MAX_STRING];
	char userID[MAX_STRING];
	strcpy(userID, session->getUserID());
	fscanf(in_fp, "%s %s", hostID, accommID);
	AccommList *list = allAccommList -> searchAccomm(accommID, 0, 3);
	Accomm* accomm = list -> getHead();
	reservManager -> addNewReservation(userID , accomm, allReservList);
	fprintf(out_fp, "4.2. 숙소예약\n");
	int date = accomm->getDate();
	fprintf(out_fp, "> %s %s %s %d:%d:%d %d\n", accomm->getHostID(), accomm->getID(), accomm->getCity(), date/10000, (date%10000)/100, date%100, accomm->getPrice());
}

void ReservAccommUI::opqReservUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList, AccommManager* accommManager)
{
	char city[MAX_STRING], date[MAX_STRING];
	char userID[MAX_STRING];
	char year[5], month[3], day[3];
	int targetPrice = 0;
	int successCheck = 0;
	int intDate = 0;
	strcpy(userID, session->getUserID());
	fscanf(in_fp, "%s %s %d", city, date, &targetPrice);
	for(int i = 0 ; i < 4 ; i++){
		year[i] = date[i];
	}
	year[4] = '\0';
	for(int i = 0 ; i < 2 ; i++){
		month[i] = date[i+5];
		day[i] = date[i+8];
	}	
	month[2] = '\0';
	day[2] = '\0';
	intDate += atoi(year)*10000;
	intDate += atoi(month)*100;
	intDate += atoi(day);
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
		fprintf(out_fp, "> Success %s %s %s %d:%d:%d %d\n",accomm->getHostID(), accomm->getID(), accomm->getCity(), intDate/10000, (intDate%10000)/100, intDate%100, accomm->getOpqPrice());
	}else{
		fprintf(out_fp, "> Try again in 24 hours\n");
	}
}