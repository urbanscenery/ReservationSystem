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
	if(searchMethod == 1){
		list -> alignAccommList(1);
	}else if(searchMethod == 2){
		list -> alignAccommList(2);
	}
	return list;
}

int AccommManager::addNewAccomm(char* userID, char * accommID, char * city, int price, int date, int opqPrice, AccommList* allAccommList)
{
	Accomm* point = allAccommList->getHead();
	int size = allAccommList->getCount();
	bool already = false;				//±âÁ¸¿¡ µî·ÏµÈ ¼÷¼ÒÀÎÁö ¾Ë·ÁÁÖ´Â flag º¯¼ö

	for (int i = 0; i < size; i++) {
		if (!strcmp(point->getID(), accommID))	//ÀÌ¹Ì µî·ÏµÈ ¼÷¼ÒID¿Í µî·ÏÇÏ·Á´Â ¼÷¼ÒID¸¦ ºñ±³
		{
			already = true;				//ÀÌ¹Ì Á¸ÀçÇÏ´Â °æ¿ì 
			return -1;					//¼÷¼Ò µî·Ï Ãë¼Ò flag(-1)À» ¸®ÅÏÇÑ´Ù.
		}
		point = point->getNext();		//ÇöÀç accomm °´Ã¼ÀÇ ID¿Í ÀÏÄ¡ÇÏÁö ¾Ê´Â °æ¿ì, ´ÙÀ½ °´Ã¼¸¦ Á¶»çÇÑ´Ù.
	}

//	Accomm* newAccomm = new Accomm(accommID, city, price, date, opqPrice, userID);	//»õ·Î¿î ¼÷¼Ò³ëµå »ý¼º
	allAccommList->insertNode(accommID, city, price, date, opqPrice);			//»ý¼ºÇÑ ¼÷¼Ò³ëµå¸¦ ¼÷¼Ò¸®½ºÆ®¿¡»ðÀÔ
	return 1;						//Á¤»óÀûÀ¸·Î ¼÷¼Ò¸¦ µî·ÏÇßÀ½À» ¾Ë¸®´Â flagr(1)À» ¸®ÅÏÇÑ´Ù.
}

void AccommManager::alignPrice(AccommList* list)
{
	list -> alignAccommList(2);
}
void AccommManager::alignDate(AccommList* list)
{
	list -> alignAccommList(1);
}
