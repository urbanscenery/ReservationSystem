#define _CRT_SECURE_NO_WARNINGS
#include "MainUI.h"

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
		fprintf(out_fp, "1.1. 회원가입\n");
		fprintf(out_fp, "> %s %s %s %s %s %s\n", memberType, name, residentNum, address, userID, userPwd);
	}
	else
	{
		fprintf(out_fp, "1.1. 회원가입\n");
		fprintf(out_fp, "> 회원가입 실패 : 이미 존재하는 ID\n");
	}
}

void MainUI::withdrawal(FILE *in_fp, FILE *out_fp, Member **memberList)
{
	MemberManager memberManager;
	bool successWithdrawal;
	char userID[MAX_STRING];
	fscanf(in_fp, "%s", userID);
	successWithdrawal = memberManager.withdrawal(memberList, userID);
	if (successWithdrawal)
	{
		fprintf(out_fp, "1.2. 회원탈퇴\n");
		fprintf(out_fp, "> %s\n", userID);
	}
	else
	{
		fprintf(out_fp, "1.2. 회원탈퇴\n");
		fprintf(out_fp, "> 회원탈퇴 실패 : 유효하지 않은 ID\n");
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

		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "> %s %s\n", userID, userPwd);
	}
	else
	{
		fprintf(out_fp, "2.1. 로그인\n");
		fprintf(out_fp, "> 로그인 실패 : ID 혹은 비밀번호 불일치\n");
	}
}

void MainUI::logOut(FILE *in_fp, FILE *out_fp, Member **currentUser, Session **sessionList, int *currentSession)
{
	MemberManager memberManager;
	fprintf(out_fp, "2.2. 로그아웃\n> %s\n", (*currentUser)->getUserID());
	memberManager.logOut(sessionList, (*currentUser)->getUserID());
	*currentSession = 0;
}

void MainUI::changeUserSession(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession)
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
		fprintf(out_fp, "6.1. Session 변경\n> Sessino 변경 실패 : Session에 해당 ID 없음\n"); // 임시 에러
	else
	{
		*currentUser = memberManager.getSession(memberList, userID);
		if (strcmp("guest", (*currentUser)->getMemberType()) == 0)
			*currentSession = 1;
		else
			*currentSession = 2;
		fprintf(out_fp, "6.1. Session 변경\n> %s\n", userID);
	}

}
void MainUI::setTime(FILE *in_fp, FILE *out_fp, AccommManager* accommManager, AccommList* allAccommList, Timer *currentTime){
	char time[MAX_STRING];
	int intDate, intTime;
	fscanf(in_fp, "%s", time);
	intDate = stoiDate(time);
	intTime = stoiTime(time);
	currentTime -> setTimer(intDate, intTime);
	fprintf(out_fp, "5.1.현재시간 설정\n");
	fprintf(out_fp, "> %s\n", time);

	Accomm* point = allAccommList -> getHead();

	for (int i = 0, max = allAccommList -> getCount(); i < max ; i++) {
		(point->getAccommTimer())->expiredAccomm(currentTime->getDate());			//현재시간과 비교하여 숙소타이머 재설정 (타이머동작)
		point = point->getNext();
	}

	accommManager -> checkExpiredAccomm(allAccommList);

}
void MainUI::changeGuestSession(FILE *out_fp, Member **currentUser, int *currentSession)
{
	fprintf(out_fp, "6.2. Gueset session으로 변경\n");
	*currentUser = NULL;
	*currentSession = 0;
}
void MainUI::program_error(FILE *out_fp, int menu_level_1, int menu_level_2)
{
	fprintf(out_fp, "%d.%d. 유효하지 않은 메뉴 입력\n", menu_level_1, menu_level_2);
}
void MainUI::program_exit(FILE *out_fp)
{
	fprintf(out_fp, "7.1 종료\n");
}