
#include "Member.h"


Member::Member()
{
}
Member::Member(char *newMemberType, char *newName, char *newResidentNum, char *newAddress, char *newUserID, char *newUserPwd)
{
	strcpy(userID, newUserID);
	strcpy(userPwd, newUserPwd);
	strcpy(name, newName);
	strcpy(residentNum, newResidentNum);
	strcpy(address, newAddress);
	strcpy(memberType, newMemberType);
}

Member::~Member()
{
}

Member *Member::getNext()
{
	return next;
}

void Member::setNext(Member *nextMember)
{
	next = nextMember;
}

void Member::addMember()
{

}
void Member::deleteMember()
{

}


char *Member::getUserID()
{
	return userID;
}

char *Member::getUserPwd()
{
	return userPwd;
}

char *Member::getName()
{
	return name;
}

char *Member::getResidentNum()
{
	return residentNum;
}

char * Member::getAddress()
{
	return address;
}

char * Member::getMemberType()
{
	return memberType;
}
