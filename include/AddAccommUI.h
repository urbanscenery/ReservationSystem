#pragma once
#include <stdio.h>
#include "Session.h"
#include "AccommManager.h"

class AddAccommUI
{
public:
	AddAccommUI();
	~AddAccommUI();
	void enterInfo(Session* session, FILE * in_fp, FILE * out_fp, AccommManager* accommManager, AccommList *allAccommList);
};

extern AddAccommUI addAccommUI;
