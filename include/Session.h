#pragma once
#include <cstring>
#define MAX_STRING 32

class Session
{
private:
	char userID[MAX_STRING];
	//int memberType;
	Session *next;
public:
	Session();
	Session(char *newUserID);
	//SessionList(char *newUserID, char *newMemberType);
	~Session();
	char *getUserID();
	//int getMemberType();
	Session *getNext();
	void setNext(Session *nextLogIn);
};

