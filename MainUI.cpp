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
	// �Է� ���� : ���������, �̸�, �ֹι�ȣ, �ּ�, ID, Pwd�� ���Ϸκ��� ����
	fscanf(in_fp, "%s %s %s %s %s %s", memberType, name, residentNum, address, userID, userPwd);
	//���̵� �ߺ� Ȯ��
	successSignUp = memberManager.checkID(memberList, userID);
	if (successSignUp)
	{
		// �ش� ��� ����  
		memberManager.addNewMember(memberList, memberType, name, residentNum, address, userID, userPwd);
		// ��� ����
		fprintf(out_fp, "1.1. ȸ������\n");
		fprintf(out_fp, "> %s %s %s %s %s %s\n", memberType, name, residentNum, address, userID, userPwd);
	}
	else
	{
		fprintf(out_fp, "1.1. ȸ������\n");
		fprintf(out_fp, "> ȸ������ ���� : �̹� �����ϴ� ID\n");
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
		fprintf(out_fp, "1.2. ȸ��Ż��\n");
		fprintf(out_fp, "> %s\n", userID);
	}
	else
	{
		fprintf(out_fp, "1.2. ȸ��Ż��\n");
		fprintf(out_fp, "> ȸ��Ż�� ���� : ��ȿ���� ���� ID\n");
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

		fprintf(out_fp, "2.1. �α���\n");
		fprintf(out_fp, "> %s %s\n", userID, userPwd);
	}
	else
	{
		fprintf(out_fp, "2.1. �α���\n");
		fprintf(out_fp, "> �α��� ���� : ID Ȥ�� ��й�ȣ ����ġ\n");
	}
}

void MainUI::logOut(FILE *in_fp, FILE *out_fp, Member **currentUser, Session **sessionList, int *currentSession)
{
	MemberManager memberManager;
	fprintf(out_fp, "2.2. �α׾ƿ�\n> %s\n", (*currentUser)->getUserID());
	memberManager.logOut(sessionList, (*currentUser)->getUserID());
	*currentSession = 0;
}

void MainUI::changeUserSession(FILE *in_fp, FILE *out_fp, Member **memberList, Member **currentUser, Session **sessionList, int *currentSession)
{
	MemberManager memberManager;

	Session *position = *sessionList;
	char userID[MAX_STRING];
	fscanf(in_fp, "%s", userID);
	while (position != NULL) // �ش� ID�� ���ǿ� �ִ°�
	{
		if (strcmp(position->getUserID(), userID) == 0)
			break;
		position = position->getNext();
	}
	if (position == NULL)
		fprintf(out_fp, "6.1. Session ����\n> Sessino ���� ���� : Session�� �ش� ID ����\n"); // �ӽ� ����
	else
	{
		*currentUser = memberManager.getSession(memberList, userID);
		if (strcmp("guest", (*currentUser)->getMemberType()) == 0)
			*currentSession = 1;
		else
			*currentSession = 2;
		fprintf(out_fp, "6.1. Session ����\n> %s\n", userID);
	}

}
void MainUI::setTime(FILE *in_fp, FILE *out_fp, AccommManager* accommManager, AccommList* allAccommList, Timer *currentTime){
	char time[MAX_STRING];
	int intDate, intTime;
	fscanf(in_fp, "%s", time);
	intDate = stoiDate(time);
	intTime = stoiTime(time);
	currentTime -> setTimer(intDate, intTime);
	fprintf(out_fp, "5.1.����ð� ����\n");
	fprintf(out_fp, "> %s\n", time);

	Accomm* point = allAccommList -> getHead();

	for (int i = 0, max = allAccommList -> getCount(); i < max ; i++) {
		(point->getAccommTimer())->expiredAccomm(currentTime->getDate());			//����ð��� ���Ͽ� ����Ÿ�̸� �缳�� (Ÿ�̸ӵ���)
		point = point->getNext();
	}

	accommManager -> checkExpiredAccomm(allAccommList);

}
void MainUI::changeGuestSession(FILE *out_fp, Member **currentUser, int *currentSession)
{
	fprintf(out_fp, "6.2. Gueset session���� ����\n");
	*currentUser = NULL;
	*currentSession = 0;
}
void MainUI::program_error(FILE *out_fp, int menu_level_1, int menu_level_2)
{
	fprintf(out_fp, "%d.%d. ��ȿ���� ���� �޴� �Է�\n", menu_level_1, menu_level_2);
}
void MainUI::program_exit(FILE *out_fp)
{
	fprintf(out_fp, "7.1 ����\n");
}