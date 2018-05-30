#pragma once
#define MAX_STRING 32 
class Timer
{
private: 
	char time[MAX_STRING];
public:
	Timer();
	~Timer();
	char* getTimer();
	void setTimer(char* date);
};

