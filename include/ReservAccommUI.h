#pragma once
#include <math.h>
#include "ReservManager.h"
#include "AccommManager.h"
#include "Session.h"
#include "tool.h"

class ReservManager;

class ReservAccommUI
{
public:
	void startAddReservUI(Member** currentUser, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList);
	void opqReservUI(Member** currentUser, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList, AccommManager* accommManager, Timer* currentTime);
};