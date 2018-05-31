#pragma once
#include "Member.h"
#include "Session.h"

class MemberManager
{
public:
	MemberManager();
	~MemberManager();

	bool checkID(Member **memberList, char *userID);
	bool checkPW();
	bool checkInfo();
	bool checkValid();
	Member *logIn(Member **memberList, char *userID, char *userPwd);
	void logOut(Session **sessionList, char *userID);
	Member *getSession(Member **memberList, char *userID);
	bool withdrawal(Member **memberList, char *userID);
	void addNewMember(Member **memberList, char *memberType, char *name, char *residentNum, char *address, char *userID, char *userPwd);
};

//extern MemberManager memberManager;