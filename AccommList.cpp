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
void AccommList::insertNode(char * accommID, char* city, int price, char* date, int opqPrice) {
	

	Accomm* newAccomm = new Accomm(accommID, city, price, date, opqPrice);	//새로운 숙소노드 생성

	tail->setNext(newAccomm);	//숙소리스트 마지막에 새로운 숙소노드를 추가한다.
	tail = newAccomm;			//마지막 포인터는 새로운 숙소노드를 가리키게 재설정한다.
	count++;					//숙소가 추가되었으므로 count증가
	displayAccommList();		//확인차..(삭제예정)
}

void AccommList::displayAccommList()
{
	//모든 숙소 리스트를 화면에 보여준다. 테스트용 함수
	Accomm * temp = head->getNext();

	for (int i = 0; i < count; i++) {
		temp->getAccommDetails();
		temp = temp->getNext();
	}
	//cout << "현재 카운트는 " << count << endl;
}
