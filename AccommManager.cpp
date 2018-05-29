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
	//등록 숙소 조회 
	Accomm* point = member.accommList->getHead();
	int size = member.accommList->getCount();
	Accomm* AccommArray = new Accomm[size];	//검색된 숙소를 담는 배열
	extern FILE * out_fp;

	fprintf(out_fp, "3.2. 등록 숙소 조회\n");

	for (int i = 0; i < size; i++) {
		point->getAccommLists();		//등록 숙소 상세정보 출력
		point = point->getNext();
	}
	fprintf(out_fp, "\n");	//줄간격 맞추기 위해 추가
}

void AccommManager::getAccommDetails()
{

}

int AccommManager::addNewAccomm(char * accommID, char * city, int price, char* date, int opqPrice)
{
	//기존에 등록한 숙소이름인지 테스트
	Accomm* point = member.accommList->getHead();
	int size = member.accommList->getCount();

	bool already = false;
	for (int i = 0; i < member.accommList->getCount(); i++) {
		if (strcmp(point->getAccommDetails(), accommID) == 0)	//이미 등록된 숙소ID와 등록하려는 숙소ID를 비교
		{
			already = true;
			return -1;
		}
		point = point->getNext();
	}
	
	//<?> opqPrice 없는 경우는?


	//테스트결과 없는 숙소이면 숙소를 등록한다
	//Accomm * newAccomm = new Accomm;
	//newAccomm->setData(accommID, city, price, date, opqPrice);
	if (already == false)
	{
		member.accommList->insertNode(accommID, city, price, date, opqPrice);		//숙소리스트에 숙소 추가
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
