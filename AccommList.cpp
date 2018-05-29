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
	printf("%s %s %d %d %d **** \n", newAccomm -> getID(), newAccomm -> getCity(), newAccomm -> getPrice(), newAccomm -> getDate(), newAccomm -> getOpqPrice() );

	tail->setNext(newAccomm);	//숙소리스트 마지막에 새로운 숙소노드를 추가한다.
	tail = newAccomm;			//마지막 포인터는 새로운 숙소노드를 가리키게 재설정한다.
	count++;					//숙소가 추가되었으므로 count증가
	displayAccommList();		//확인차..(삭제예정)
}

void AccommList::displayAccommList()
{
	Accomm * temp = head->getNext();

	for (int i = 0; i < count; i++) {
		printf("%s ", temp->getID());
		temp = temp->getNext();
	}
	printf("\n");
}

AccommList* AccommList::searchAccomm(char* city, int date)
{
	AccommList* list = new AccommList();
	Accomm* accomm = this -> getHead();
	for (int i = 0, max = this -> getCount() ; i < max ; i++) {
		if (!strcmp(city, accomm->getCity()) && (date == accomm->getDate())) {
			list -> insertNode(accomm->getID(), accomm->getCity(), accomm->getPrice(), accomm->getDate(), accomm->getOpqPrice());
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