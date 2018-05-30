#define _CRT_SECURE_NO_WARNINGS
#include "AddAccommUI.h"


AddAccommUI::AddAccommUI()
{
}


AddAccommUI::~AddAccommUI()
{
}

void AddAccommUI::enterInfo(Session* session, FILE * in_fp, FILE * out_fp, AccommManager* accommManager, AccommList *allAccommList)
{
	char accommID[MAX_STRING], city[MAX_STRING], date[MAX_STRING];
	char year[5], month[3], day[3];
	int price = 0, opqPrice = 0;
	int result;			//¼÷¼Ò µî·Ï ¼º°ø, ½ÇÆÐ ¿©ºÎ
	char userID[MAX_STRING];
	int intDate = 0;
	strcpy(userID, session->getUserID());
	// ÀÔ·Â Çü½Ä : ¼÷¼ÒÀÌ¸§, µµ½Ã¸í, °¡°Ý, ³¯Â¥, opaque °¡°Ý Á¤º¸¸¦ ÆÄÀÏ·ÎºÎÅÍ ÀÐÀ½
	fscanf(in_fp, "%s %s %d %s %d", accommID, city, &price, date, &opqPrice);
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
	result = accommManager->addNewAccomm(userID, accommID, city, price, intDate, opqPrice, allAccommList);

	if (result == 1)
	{
		fprintf(out_fp, "3.1. 숙소등록\n");
		fprintf(out_fp, "> %s %s %d %d %d\n\n", accommID, city, price, intDate, opqPrice);
	}
	else if (result == -1)
	{
		fprintf(out_fp, "> Fail to regist accommodation.\n\n");
	}
}

