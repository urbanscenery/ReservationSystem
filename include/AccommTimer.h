#pragma once
#include "Timer.h"
class AccommTimer : public Timer
{
public:
	AccommTimer();
	~AccommTimer();

private: 
	void expiredAccomm();
};

