#include "AccommList.h"
#include <iostream>

AccommList::AccommList()
{	//���� ����Ʈ �ʱ�ȭ
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
	Accomm* newAccomm = new Accomm(accommID, city, price, date, opqPrice);	//���ο� ���ҳ�� ����
	printf("%s %s %d %d %d **** \n", newAccomm -> getID(), newAccomm -> getCity(), newAccomm -> getPrice(), newAccomm -> getDate(), newAccomm -> getOpqPrice() );

	tail->setNext(newAccomm);	//���Ҹ���Ʈ �������� ���ο� ���ҳ�带 �߰��Ѵ�.
	tail = newAccomm;			//������ �����ʹ� ���ο� ���ҳ�带 ����Ű�� �缳���Ѵ�.
	count++;					//���Ұ� �߰��Ǿ����Ƿ� count����
	displayAccommList();		//Ȯ����..(��������)
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