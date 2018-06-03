#pragma once
#include <cstring>
#include <iostream>
#include "MemberTimer.h"

#define MAX_STRING 32

using namespace std;

class Member
{
private:
	char userID[MAX_STRING];
	char userPwd[MAX_STRING];
	char name[MAX_STRING];
	char residentNum[MAX_STRING];
	char address[MAX_STRING];
	char memberType[MAX_STRING];
	Member *next;
	MemberTimer memberTimer;

public:
	Member();
	Member(char *newMemberType, char *newName, char *newResidentNum, char *newAddress, char *newUserID, char *newUserPwd);
	~Member();
	char *getUserID();
	char *getUserPwd();
	char *getName();
	char *getResidentNum();
	char *getAddress();
	char *getMemberType();
	Member *getNext();
	void setNext(Member *nextMember);
	void addMember();
	void deleteMember();
	MemberTimer* getMemberTimer();
};

extern Member member;