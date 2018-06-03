#pragma once
#include "Session.h"
#include "AccommManager.h"
#include "tool.h"

class AddAccommUI
{
public:
	AddAccommUI();
	~AddAccommUI();
	void enterInfo(Member** currentUser, FILE * in_fp, FILE * out_fp, AccommManager* accommManager, AccommList *allAccommList, Timer* currentTime);
};

extern AddAccommUI addAccommUI;
