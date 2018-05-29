#pragma once
#include "Accomm.h"
#include "AccommList.h"
//#include "Member.h"
class AccommManager
{
public:
	AccommManager();
	~AccommManager();
	int getAccommLists();
	void getAccommDetails();
	int addNewAccomm(char * accommID, char * city, int price, char* date, int opqPrice);
	void getAvailableDate();
	void deleteAccomm();
	void setOpaqueOption();
	void alignPrice(AccommList list);
	void alignDate(AccommList list);

};

extern AccommManager accommManager;