#pragma once
#include "Accomm.h"
#include "AccommList.h"
//#include "Member.h"
class AccommManager
{
public:
	AccommManager();
	~AccommManager();
	AccommList* getAccommLists(char* index1, int index2, int searchMethod , AccommList* allAccommList);
	int addNewAccomm(char* userID, char * accommID, char * city, int price, int date, int opqPrice, AccommList* allAccommList);
	void alignPrice(AccommList* list);
	void alignDate(AccommList* list);
};
