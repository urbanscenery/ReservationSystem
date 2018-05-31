#pragma once
#include "Member.h"
#include "AccommList.h"

class Host : public Member
{
private:
	Accomm accommList[3];	//보유 숙소리스트


public:
	Host();
	~Host();
};

extern Host host;