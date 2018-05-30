#define _CRT_SECURE_NO_WARNINGS
#include "MainUI.h"
#include "MemberManager.h"

MainUI::MainUI()
{
}


MainUI::~MainUI()
{
}

void MainUI::signUp(FILE *in_fp, FILE *out_fp, Member **memberList)
{
	MemberManager memberManager;
	bool successSignUp;
	char memberType[MAX_STRING], name[MAX_STRING], residentNum[MAX_STRING],
		address[MAX_STRING], userID[MAX_STRING], userPwd[MAX_STRING];
	// 입력 형식 : 사용자유형, 이름, 주민번호, 주소, ID, Pwd를 파일로부터 읽음
	fscanf(in_fp, "%s %s %s %s %s %s", memberType, name, residentNum, address, userID, userPwd);
	//아이디 중복 확인
	successSignUp = memberManager.checkID(memberList, userID);
	if (successSignUp)
	{
		// 해당 기능 수행  
		memberManager.addNewMember(memberList, memberType, name, residentNum, address, userID, userPwd);
		// 출력 형식
		fprintf(out_fp, "1.1. Sign up\n");
		fprintf(out_fp, "> %s %s %s %s %s %s\n", memberType, name, residentNum, address, userID, userPwd);
	}
	else
	{
		fprintf(out_fp, "1.1. Sign up\n");
		fprintf(out_fp, "> Fail to sign up\n");
	}
}

void MainUI::logIn(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession)
{
	MemberManager memberManager;

	Member *tmp;
	Session *position, *newSession;
	char userID[MAX_STRING], userPwd[MAX_STRING];
	fscanf(in_fp, "%s %s", userID, userPwd);
	tmp = memberManager.logIn(memberList, userID, userPwd);
	if (tmp != NULL)
	{
		*currentUser = tmp;
		newSession = new Session((*currentUser)->getUserID());
		position = *sessionList;
		if (*sessionList == NULL)
			*sessionList = newSession;
		else
		{
			while (position->getNext() != NULL)
				position = position->getNext();
			position->setNext(newSession);
		}


		if (strcmp("guest", (*currentUser)->getMemberType()) == 0)
			*currentSession = 1;
		else
			*currentSession = 2;

		fprintf(out_fp, "2.1. Sign in\n");
		fprintf(out_fp, "> %s %s\n", userID, userPwd);
	}
	else
	{
		fprintf(out_fp, "2.1. Sign in \n");
		fprintf(out_fp, "> Fail to sign in\n");
	}
}

void MainUI::logOut(FILE *in_fp, FILE *out_fp, Member **currentUser, Session **sessionList, int *currentSession)
{
	MemberManager memberManager;
	fprintf(out_fp, "2.2. Log out\n> %s\n", (*currentUser)->getUserID());
	memberManager.logOut(sessionList, (*currentUser)->getUserID());
	*currentSession = 0;

}

void MainUI::changeSession(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession)
{
	MemberManager memberManager;

	Session *position = *sessionList;
	char userID[MAX_STRING];
	fscanf(in_fp, "%s", userID);
	while (position != NULL) // 해당 ID가 세션에 있는가
	{
		if (strcmp(position->getUserID(), userID) == 0)
			break;
		position = position->getNext();
	}
	if (position == NULL)
	{
		return;
	}
	else
	{
		*currentUser = memberManager.getSession(memberList, userID);
		if (strcmp("guest", (*currentUser)->getMemberType()) == 0)
			*currentSession = 1;
		else
			*currentSession = 2;
		fprintf(out_fp, "6.1. Session change \n> %s\n", userID);
	}

}