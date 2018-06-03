#include "Timer.h"

Timer::Timer()
{
}

Timer::Timer(int currentTime)
{
	date = currentTime;
}


Timer::~Timer()
{
}

int Timer::getDate()
{
	return date;
}

int Timer::getTime()
{
	return time;
}

void Timer::setTimer(int date, int time)
{
	this -> date = date;
	this -> time = time;
}
