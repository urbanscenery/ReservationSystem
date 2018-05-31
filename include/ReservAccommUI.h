#pragma once
#include "ReservManager.h"
#include "AccommManager.h"
#include "Session.h"

class ReservManager;

class ReservAccommUI
{
public:
	void startAddReservUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList);
	void opqReservUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList, AccommList* allAccommList, AccommManager* accommManager);
};