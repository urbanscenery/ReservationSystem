#pragma once
#include<string.h>
#include "ReservManager.h"
#include "ReservList.h"
#include "AccommList.h"
#include "AccommManager.h"
#include "Session.h"

#define MAX_STRING 32
using namespace std;

class ReservManager;

class ReservAccommUI
{
public:
	void startAddReservUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList);
	void opqReservUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList, AccommManager* accommManager);
};