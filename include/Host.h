#pragma once
#include "Member.h"
#include "AddAccommUI.h"

class Host : public Member
{
private:
	Accomm accommList[3];	//���� ���Ҹ���Ʈ


public:
	Host();
	~Host();
};

extern Host host;