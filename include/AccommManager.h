#pragma once
#include "Accomm.h"
#include "Member.h"
class AccommManager
{
public:
	AccommManager();
	~AccommManager();
	void getAccommLists();
	void getAccommDetails();
	int addNewAccomm(char * accommID, char * city, int price, char* date, int opqPrice);
	void getAvailableDate();
	void deleteAccomm();
	void setOpaqueOption();
	void alignAccommLists();
};

extern AccommManager accommManager;