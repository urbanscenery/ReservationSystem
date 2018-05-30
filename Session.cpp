#include "Session.h"



Session::Session()
{
}


Session::Session(char *newUserID)
{
	strcpy(userID, newUserID);
}

/*Session::Session(char *newUserID, char *newMemberType)
{
strcpy_s(userID, sizeof(userID), newUserID);
if (strcmp("guest", newMemberType) == 0)
memberType = 1;
else
memberType = 2;
}*/




Session::~Session()
{
}

char *Session::getUserID()
{
	return userID;
}

/*int Session::getMemberType()
{
	return memberType;
}*/

Session *Session::getNext()
{
	return next;
}
void Session::setNext(Session *nextSession)
{
	next = nextSession;
}