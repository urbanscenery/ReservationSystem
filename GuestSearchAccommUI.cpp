#include "GuestSearchAccommUI.h"

void GuestSearchAccommUI::startUI(FILE* in_fp, FILE* out_fp, AccommManager* accommManager, AccommList* allAccommList)
{
	char city[MAX_STRING], date[MAX_STRING];
	int intDate = 0;
	fscanf(in_fp, "%s %s", city, date);
	intDate = stoiDate(date);
	AccommList* list = accommManager -> getAccommLists(city, intDate, 2, allAccommList);
	fprintf(out_fp, "4.1. 숙소검색\n");
	Accomm* accomm = list -> getHead();
	for(int i = 0 , max = list->getCount(); i < max ; i++){
		fprintf(out_fp, "> %s %s %s %d\n", accomm->getHostID(), accomm -> getID(), accomm -> getCity(), accomm -> getPrice() );
		accomm = accomm -> getNext();
	}

}