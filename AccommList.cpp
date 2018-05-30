#include "AccommList.h"
#include <iostream>

AccommList::AccommList()
{	//숙소 리스트 초기화
	head = new Accomm();
	tail = head;
	count = 0;
}


AccommList::~AccommList()
{
}

int AccommList::getCount()
{
	return count;
}

Accomm* AccommList::getHead() {
	return head->getNext();
}
void AccommList::insertNode(char * accommID, char* city, int price, int date, int opqPrice) {
	Accomm* newAccomm = new Accomm(accommID, city, price, date, opqPrice);	//새로운 숙소노드 생성

	tail->setNext(newAccomm);
	tail = newAccomm;
	count++;
	displayAccommList();
}

void AccommList::displayAccommList()
{
	Accomm * temp = head->getNext();

	for (int i = 0; i < count; i++) {
		temp = temp->getNext();
	}
}

AccommList* AccommList::searchAccomm(char* index1, int date, int searchMethod)
{
	AccommList* list = new AccommList();
	Accomm* accomm = this -> getHead();
	for (int i = 0, max = this -> getCount() ; i < max ; i++) {
		if (searchMethod == 2) {
			if (!strcmp(index1, accomm->getCity()) && (date == accomm->getDate())) {
				list -> insertNode(accomm->getID(), accomm->getCity(), accomm->getPrice(), accomm->getDate(), accomm->getOpqPrice());
			}
			accomm = accomm -> getNext();
		}
		else if(searchMethod == 3 ){
			if (!strcmp(index1, accomm->getID())) {
				list -> insertNode(accomm->getID(), accomm->getCity(), accomm->getPrice(), accomm->getDate(), accomm->getOpqPrice());
			}
			accomm = accomm -> getNext();
		}
		else if (searchMethod == 4) {
			if(!strcmp(index1, accomm->getCity()) && (date == accomm->getDate())) {
				if((accomm -> getOpqPrice()) > 0){
					list -> insertNode(accomm->getID(), accomm->getCity(), accomm->getPrice(), accomm->getDate(), accomm->getOpqPrice());
				}
			}
			accomm = accomm -> getNext();
		}

	}
	return list;
}

void AccommList::alignAccommList(int alignMethod)
{
	Accomm* head = this -> getHead();
	Accomm* fromPtr = this -> head;
	Accomm* temp = NULL;
	for (int i = 0 , maxi = this -> getCount() - 1; i < maxi ; i++) {
		head = this -> getHead();
		fromPtr = this -> head;
		for (int j = 0 , maxj = maxi - i ; j < maxj ; j++) {
			if (alignMethod == 1) {
				if ((head -> getDate()) > (head -> getNext() -> getDate())) {
					temp = head -> getNext();
					head -> setNext(head -> getNext() -> getNext());
					temp -> setNext(head);
					fromPtr -> setNext(temp);
					fromPtr = fromPtr -> getNext();
				}
				else {
					fromPtr = fromPtr -> getNext();
					head = head -> getNext();
				}
			}
			else {
				if ((head -> getPrice()) > (head -> getNext() -> getPrice())) {
					temp = head -> getNext();
					head -> setNext(head -> getNext() -> getNext());
					temp -> setNext(head);
					fromPtr -> setNext(temp);
					fromPtr = fromPtr -> getNext();
				}
				else {
					fromPtr = fromPtr -> getNext();
					head = head -> getNext();
				}
			}
		}
	}

}