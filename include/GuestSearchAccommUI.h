#pragma once
#include<string.h>
#include "AccommManager.h"
#include "AccommList.h"
#include "Accomm.h"

#define MAX_STRING 32
using namespace std;

class AccommManager;

class GuestSearchAccommUI
{
public:
	void startUI(FILE* in_fp, FILE* out_fp, AccommManager* accommManager, AccommList* allAccommList);
};