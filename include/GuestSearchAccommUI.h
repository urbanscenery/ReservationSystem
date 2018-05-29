#pragma once
#include<string.h>
#include "main.h"
#include "AccommManager.h"
#include "Accomm.h"

#define MAX_STRING 32
using namespace std;

class AccommManager;
class Session;

class GuestSearchAccommUI
{
public:
	void startUI(Session session, FILE* in_fp, FILE* out_fp);
};