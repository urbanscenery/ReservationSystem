#include "AccommTimer.h"



AccommTimer::AccommTimer()
{
}


AccommTimer::~AccommTimer()
{
}

void AccommTimer::expiredAccomm(int currentTime)
{
	int accommDate = getDate();
	if(currentTime - accommDate >= 10000){
		setTimer(0);
	}
}
