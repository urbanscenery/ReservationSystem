#pragma once
#include "AccommManager.h"
#include "Session.h"


class HostSearchAccommUI
{
public:
	HostSearchAccommUI();
	~HostSearchAccommUI();
	void searchAccomms(Member** currentUser, FILE* in_fp, FILE* out_fp, AccommManager* accommManager, AccommList *allAccommList);
};

