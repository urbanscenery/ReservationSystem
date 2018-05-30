#define _CRT_SECURE_NO_WARNINGS
#include "WithdrawalUI.h"
#include "MemberManager.h"

WithdrawalUI::WithdrawalUI()
{
}


WithdrawalUI::~WithdrawalUI()
{
}

void WithdrawalUI::withdrawal(FILE *in_fp, FILE *out_fp, Member **memberList)
{
	MemberManager memberManager;
	bool successWithdrawal;
	char userID[MAX_STRING];
	fscanf(in_fp, "%s", userID);
	successWithdrawal = memberManager.withdrawal(memberList, userID);
	if (successWithdrawal)
	{
		fprintf(out_fp, "1.2. Member withdrawal\n");
		fprintf(out_fp, "> %s\n", userID);
	}
	else
	{
		fprintf(out_fp, "1.2. Member withdrawal\n");
		fprintf(out_fp, "> Fail to withdrawal\n");
	}
}


/*bool WithdrawalUI::confirm()
{
	return false;
}*/