#pragma once
#include<string.h>
#include "main.h"
#include "ReservManager.h"
#include "Reservation.h"

#define MAX_STRING 32
using namespace std;

class ReservManager;
class Session;

class GuestSearchAccommUI
{
public:
	void startUI(Session session, FILE* in_fp, FILE* out_fp);
};