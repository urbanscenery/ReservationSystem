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
void AccommList::insertNode(char * accommID, char* city, int price, char* date, int opqPrice) {
	

	Accomm* newAccomm = new Accomm(accommID, city, price, date, opqPrice);	//���ο� ���ҳ�� ����

	tail->setNext(newAccomm);	//���Ҹ���Ʈ �������� ���ο� ���ҳ�带 �߰��Ѵ�.
	tail = newAccomm;			//������ �����ʹ� ���ο� ���ҳ�带 ����Ű�� �缳���Ѵ�.
	count++;					//���Ұ� �߰��Ǿ����Ƿ� count����
	displayAccommList();		//Ȯ����..(��������)
}

void AccommList::displayAccommList()
{
	//��� ���� ����Ʈ�� ȭ�鿡 �����ش�. �׽�Ʈ�� �Լ�
	Accomm * temp = head->getNext();

	for (int i = 0; i < count; i++) {
		temp->getAccommDetails();
		temp = temp->getNext();
	}
	//cout << "���� ī��Ʈ�� " << count << endl;
}
