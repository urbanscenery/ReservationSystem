#include "GuestSearchAccommUI.h"

void GuestSearchAccommUI::startUI(FILE* in_fp, FILE* out_fp, AccommManager* accommManager, AccommList* allAccommList)
{
	char city[MAX_STRING], date[MAX_STRING];
	char year[5], month[3], day[3];
	int intDate = 0;
	fscanf(in_fp, "%s %s", city, date);
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
	AccommList* list = accommManager -> getAccommLists(city, intDate, 2, allAccommList);
	fprintf(out_fp, "4.1. 숙소검색\n");
	Accomm* accomm = list -> getHead();
	for(int i = 0 , max = list->getCount(); i < max ; i++){
		fprintf(out_fp, "> %s %s %s %d\n", accomm->getHostID(), accomm -> getID(), accomm -> getCity(), accomm -> getPrice() );
		accomm = accomm -> getNext();
	}

}