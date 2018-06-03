#pragma once
#include "Timer.h"
#include "tool.h"

class AccommTimer : public Timer
{
public:
	AccommTimer();
	~AccommTimer();
	void expiredAccomm(int currentTime);
};

