#pragma once
#include "MemberManager.h"
#include "AccommManager.h"
#include "Timer.h"

class MainUI
{
public:
	MainUI();
	~MainUI();
	void signUp(FILE *in_fp, FILE *out_fp, Member **memberList);
	void withdrawal(FILE *in_fp, FILE *out_fp, Member **memberList);
	void logIn(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession);
	void logOut(FILE *in_fp, FILE *out_fp, Member **currentUser , Session **sessionList, int *currentSession);
	void changeUserSession(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession);
	void changeGuestSession(FILE *out_fp, Member **currentUser, int *currentSession);
	void setTime(FILE *in_fp, FILE *out_fp, AccommManager* accommManager, AccommList* allAccommList, Timer *currentTime);
	void program_error(FILE *out_fp, int menu_level_1, int menu_level_2);
	void program_exit(FILE *out_fp);
};

