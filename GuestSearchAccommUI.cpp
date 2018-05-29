#include "GuestSearchAccommUI.h"

void GuestSearchAccommUI::startUI(Session session, FILE* in_fp, FILE* out_fp)
{
	char city[MAX_STRING], date[MAX_STRING];
	char year[5], month[3], day[3];
	int intDate = 0;
	fscanf(in_fp, "%s %s", city, date);
	for(int i = 0 ; i < 4 ; i++){
		year[i] = date[i];
	}
	year[4] = NULL;
	for(int i = 0 ; i < 2 ; i++){
		month[i] = date[i+5];
		day[i] = date[i+8];
	}	
	month[2] = NULL;
	day[2] = NULL;
	intDate += atoi(year)*10000;
	intDate += atoi(month)*100;
	intDate += atoi(day);

	Accomm* newAccomm = new Accomm("a", "daegu", 10000, 20170101, 100000);
	printf("%s %s %d %d %d ----- \n", newAccomm -> getID(), newAccomm -> getCity(), newAccomm -> getPrice(), newAccomm -> getDate(), newAccomm -> getOpqPrice() );

}