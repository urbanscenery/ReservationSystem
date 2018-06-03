#pragma once
#include <string.h>
//#include "AccommList.h"

#define MAX_STRING 32 

class Timer
{
private: 
	int date;
	int time;
public:
	Timer();
	Timer(int currentTime);
	~Timer();
	int getDate();
	int getTime();
	void setTimer(int date, int time = 0);
};

