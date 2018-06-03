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
void AccommList::insertNode(char * accommID, char* city, int price, int date, int opqPrice, char* hostID, int currentTime) {
	Accomm* newAccomm = new Accomm(accommID, city, price, date, opqPrice, hostID, currentTime);
	tail->setNext(newAccomm);
	tail = newAccomm;
	count++;
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
			if (searchMethodCheck(index1, date, accomm,searchMethod)) {
				list -> insertNode(accomm->getID(), accomm->getCity(), accomm->getPrice(), 
														accomm->getDate(), accomm->getOpqPrice(), accomm-> getHostID(), accomm-> getAccommTimer() -> getDate());
			}
			accomm = accomm -> getNext();
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
				if (alignMethodCheck(head, alignMethod)) {
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

bool AccommList::searchMethodCheck(char* index1, int date, Accomm* accomm, int method){
	if(method == 2){
		return (!strcmp(index1, accomm->getCity()) && (date == accomm->getDate()));
	}else if(method == 3){
		return (!strcmp(index1, accomm->getID()));
	}else if(method == 4){
		return (!strcmp(index1, accomm->getCity()) && (date == accomm->getDate()) 
						&& (accomm -> getOpqPrice()) > 0);
	}
}

bool AccommList::alignMethodCheck(Accomm* accomm, int method){
	if(method == 1){
		return ((accomm -> getDate()) > (accomm -> getNext() -> getDate()));
	}else if(method == 2){
		return ((accomm -> getPrice()) > (accomm -> getNext() -> getPrice()));
	}
}

void AccommList::deleteNode()
{
	Accomm* before = head;
	Accomm* current = head->getNext();
	Accomm* temp = NULL;
		

	while(current!=NULL){
		if (current->getAccommTimer()->getDate() == 0 ) {
			before->setNext(current->getNext());
			if (current == tail) tail = before;
			temp = current;
			current = current->getNext();
			delete temp;
			count--;
		}
		else {
			before = current;
			current = current->getNext();

		}
	}
}


