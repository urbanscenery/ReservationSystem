#include "AccommManager.h"
#include <iostream>


AccommManager::AccommManager()
{
}


AccommManager::~AccommManager()
{
}

AccommList* AccommManager::getAccommLists(char* index1, int index2, int searchMethod, AccommList* allAccommList)
{
	AccommList* list = allAccommList -> searchAccomm(index1, index2, searchMethod);
	list -> alignAccommList(searchMethod);
	return list;
}

int AccommManager::addNewAccomm(char* userID, char * accommID, char * city, int price, int date, int opqPrice, AccommList* allAccommList, Timer* currentTime)
{
	Accomm* point = allAccommList->getHead();
	bool already = false;

	for (int i = 0, max = allAccommList->getCount(); i < max; i++) {
		if (!strcmp(point->getID(), accommID))
		{
			already = true;
			return -1;
		}
		point = point->getNext();
	}
	allAccommList->insertNode(accommID, city, price, date, opqPrice, userID, currentTime -> getDate());
	return 1;
}

void AccommManager::checkExpiredAccomm(AccommList* allAccommList) 
{
	allAccommList->deleteNode();
}