#include "AccommManager.h"
#include <iostream>


AccommManager::AccommManager()
{
}


AccommManager::~AccommManager()
{
}

void AccommManager::getAccommLists()
{
	//��� ���� ��ȸ 
	Accomm* point = member.accommList->getHead();
	int size = member.accommList->getCount();
	Accomm* AccommArray = new Accomm[size];	//�˻��� ���Ҹ� ��� �迭
	extern FILE * out_fp;

	fprintf(out_fp, "3.2. ��� ���� ��ȸ\n");

	for (int i = 0; i < size; i++) {
		point->getAccommLists();		//��� ���� ������ ���
		point = point->getNext();
	}
	fprintf(out_fp, "\n");	//�ٰ��� ���߱� ���� �߰�
}

void AccommManager::getAccommDetails()
{

}

int AccommManager::addNewAccomm(char * accommID, char * city, int price, char* date, int opqPrice)
{
	//������ ����� �����̸����� �׽�Ʈ
	Accomm* point = member.accommList->getHead();
	int size = member.accommList->getCount();

	bool already = false;
	for (int i = 0; i < member.accommList->getCount(); i++) {
		if (strcmp(point->getAccommDetails(), accommID) == 0)	//�̹� ��ϵ� ����ID�� ����Ϸ��� ����ID�� ��
		{
			already = true;
			return -1;
		}
		point = point->getNext();
	}
	
	//<?> opqPrice ���� ����?


	//�׽�Ʈ��� ���� �����̸� ���Ҹ� ����Ѵ�
	//Accomm * newAccomm = new Accomm;
	//newAccomm->setData(accommID, city, price, date, opqPrice);
	if (already == false)
	{
		member.accommList->insertNode(accommID, city, price, date, opqPrice);		//���Ҹ���Ʈ�� ���� �߰�
		return 1;
	}
}

void AccommManager::getAvailableDate()
{
}

void AccommManager::deleteAccomm()
{
}

void AccommManager::setOpaqueOption()
{
}

void AccommManager::alignAccommLists()
{
}
