#pragma once
#include "Member.h"
#include "Session.h"
#include <stdio.h>

class MainUI
{
public:
	MainUI();
	~MainUI();
	void signUp(FILE *in_fp, FILE *out_fp, Member **memberList);
	void logIn(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession);
	void logOut(FILE *in_fp, FILE *out_fp, Member **currentUser , Session **sessionList, int *currentSession);
	void changeSession(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession);
};

