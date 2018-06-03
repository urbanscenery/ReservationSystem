#pragma once
#include "ReservManager.h"
#include "Session.h"

#define MAX_STRING 32
using namespace std;

class ReservManager;

class MyReservationUI
{
public:
	void startUI(Member** currentUser, FILE* in_fp, FILE* out_fp, ReservManager* reservManager, ReservList* allReservList);
};