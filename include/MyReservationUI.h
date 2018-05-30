#pragma once
#include<string.h>
#include "ReservManager.h"
#include "ReservList.h"
#include "Reservation.h"
#include "Session.h"

#define MAX_STRING 32
using namespace std;

class ReservManager;

class MyReservationUI
{
public:
	void startUI(Session* session, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList);
};