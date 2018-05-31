#pragma once
#include "MemberManager.h"

class WithdrawalUI
{
public:
	WithdrawalUI();
	~WithdrawalUI();

	void withdrawal(FILE *in_fp, FILE *out_fp, Member **memberList);
	//bool confirm();
};


