#include "MemberManager.h"

MemberManager::MemberManager()
{
}


MemberManager::~MemberManager()
{
}



bool MemberManager::checkID(Member **memberList, char *userID)
{
	Member *position = *memberList;
	while (position != NULL)
	{
		if (strcmp(userID, position->getUserID()) == 0)
			return false;
		position = position->getNext();
	}
	return true;
}

bool MemberManager::checkPW()
{
	return false;
}
bool MemberManager::checkInfo()
{
	return false;

}
bool MemberManager::checkValid()
{
	return false;
}
Member *MemberManager::logIn(Member **memberList, char *userID, char *userPwd)
{
	Member *position = *memberList;
	while (position != NULL)
	{
		if (strcmp(userID, position->getUserID()) == 0)
			if (strcmp(userPwd, position->getUserPwd()) == 0)
				return position;
		position = position->getNext();
	}
	return NULL;
}
void MemberManager::logOut(Session **sessionList, char *userID)
{
	Session *previous, *position = *sessionList;
	previous = position;
	if (strcmp(userID, position->getUserID()) == 0)
	{
		*sessionList = (*sessionList)->getNext();
		free(position);
	}
	while (position != NULL)
	{
		if (strcmp(userID, position->getUserID()) == 0)
		{
			previous->setNext(position->getNext());
			free(position);
			break;
		}
		previous = position;
		position = position->getNext();
	}
}

Member *MemberManager::getSession(Member **memberList, char *userID)
{
	Member *position = *memberList;
	while (position != NULL)
	{
		if (strcmp(userID, position->getUserID()) == 0)
			return position;
		position = position->getNext();
	}
	return NULL;
}

bool MemberManager::withdrawal(Member **memberList, char *userID)
{
	Member *previous, *position = *memberList;
	previous = position;
	if (strcmp(userID, position->getUserID()) == 0) // head �� ���� ��
	{
		*memberList = (*memberList)->getNext();
		free(position);
		return true;
	}
	while (position != NULL)
	{
		if (strcmp(userID, position->getUserID()) == 0)
		{
			previous->setNext(position->getNext());
			free(position);
			return true;
		}
		previous = position;
		position = position->getNext();
	}
	return false;
}
// 2018-05-28 01:50
void MemberManager::addNewMember(Member **memberList, char *memberType, char *name, char *residentNum, char *address, char *userID, char *userPwd)
{
	Member *position, *previous;
	Member *newMember = new Member(memberType, name, residentNum, address, userID, userPwd);
	if (*memberList == NULL)
		*memberList = newMember;
	else
	{
		if (strcmp(newMember->getName(), (*memberList)->getName()) < 0) // �Էµ� name �� memberList �� ù member �� name���� �����ټ� ���� ��
		{
			newMember->setNext(*memberList);
			*memberList = newMember;
		}
		else
		{
			position = *memberList;
			previous = position;
			while (position != NULL && strcmp(newMember->getName(), position->getName()) > 0) // �Էµ� name �� memberList �� ������ member ����, ������ ������ ���� ��
			{
				previous = position;
				position = position->getNext();
			}
			newMember->setNext(previous->getNext());
			previous->setNext(newMember);
		}
	}
}