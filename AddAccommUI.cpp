#define _CRT_SECURE_NO_WARNINGS
#include "AddAccommUI.h"


AddAccommUI::AddAccommUI()
{
}


AddAccommUI::~AddAccommUI()
{
}

void AddAccommUI::enterInfo(Member** currentUser, FILE * in_fp, FILE * out_fp, AccommManager* accommManager, AccommList *allAccommList, Timer* currentTime)
{
	char accommID[MAX_STRING], city[MAX_STRING], date[MAX_STRING];
	int price = 0, opqPrice = 0;
	int result;			//¼÷¼Ò µî·Ï ¼º°ø, ½ÇÆÐ ¿©ºÎ
	char userID[MAX_STRING];
	int intDate = 0;
	strcpy(userID, (*currentUser) -> getUserID());
	// ÀÔ·Â Çü½Ä : ¼÷¼ÒÀÌ¸§, µµ½Ã¸í, °¡°Ý, ³¯Â¥, opaque °¡°Ý Á¤º¸¸¦ ÆÄÀÏ·ÎºÎÅÍ ÀÐÀ½
	fscanf(in_fp, "%s %s %d %s %d", accommID, city, &price, date, &opqPrice);
	intDate = stoiDate(date);
	result = accommManager->addNewAccomm(userID, accommID, city, price, intDate, opqPrice, allAccommList, currentTime);

	if (result == 1)
	{
		fprintf(out_fp, "3.1. 숙소등록\n");
		fprintf(out_fp, "> %s %s %d %s %d\n\n", accommID, city, price, date, opqPrice);
	}
	else if (result == -1)
	{
		fprintf(out_fp, "> Fail to regist accommodation.\n\n");
	}
}

