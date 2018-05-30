#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>

#include "Accomm.h"
#include "MemberManager.h"
#include "HostSearchAccommUI.h"
#include "AddAccommUI.h"
#include "AccommList.h"
#include "Host.h"
#include "Session.h"
#include "AccommManager.h"
#include "GuestSearchAccommUI.h"
#include "ReservAccommUI.h"
#include "ReservList.h"
#include "ReservManager.h"
#include "MyReservationUI.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void addNewAccomm();
void searchRegisteredAccomm();

void SignUp();
void Withdrawal();
void LogIn();
void LogOut();
void changeUserSession();
void changeGuestSession();
void program_error(int menu_level_1, int menu_level_2);
void guestSearchAccomm();
void registReservation();
void opaqueReservation();
void myReservation();

void program_exit();

FILE* in_fp, *out_fp;
int currentSession = -1;


Member *memberList, *currentUser, *logInUser;
Session *sessionList;
MemberManager memberManager;
WithdrawalUI withdrawalUI;
MainUI mainUI;

GuestSearchAccommUI guestSearchAccommUI;
ReservAccommUI reservAccommUI;

Member member = Member();
AddAccommUI addAccommUI;
HostSearchAccommUI hostSearchAccommUI;
AccommManager accommManager;
AccommList allAccommList;
ReservList allReservList;
ReservManager reservManager;
MyReservationUI myReservationUI;
Session session = Session("test");


int main()
{
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	return 0;
}


void doTask()
{
	// ¸Þ´º ÆÄ½ÌÀ» À§ÇÑ level ±¸ºÐÀ» À§ÇÑ º¯¼ö
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	while (!is_program_exit)
	{
		// ÀÔ·ÂÆÄÀÏ¿¡¼­ ¸Þ´º ¼ýÀÚ 2°³¸¦ ÀÐ±â
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		// ¸Þ´º ±¸ºÐ ¹× ÇØ´ç ¿¬»ê ¼öÇà
		switch (menu_level_1)
		{
		case 1:
		{
			if (currentSession == 0)
			{
				switch (menu_level_2)
				{
				case 1:   // "1.1. È¸¿ø°¡ÀÔ¡° ¸Þ´º ºÎºÐ
				{
					// SignUp() ÇÔ¼ö¿¡¼­ ÇØ´ç ±â´É ¼öÇà
					SignUp();
					break;
				}
				case 2:   // "1.2. È¸¿øÅ»Åð " ¸Þ´º ºÎºÐ
				{
					Withdrawal();
					break;
				}
				}
			}
			else
			{
				program_error(menu_level_1, menu_level_2);
				is_program_exit = 1;
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				if(currentSession == 0)
					LogIn();
				else
				{
					program_error(menu_level_1, menu_level_2);
					is_program_exit = 1;
				}
				break;
			}
			case 2:
			{
				if(currentSession > 0)
					LogOut();
				else
				{
					program_error(menu_level_1, menu_level_2);
					is_program_exit = 1;
				}
				break;
			}
			}
			break;		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1:		// "3.1. ¼÷¼Ò µî·Ï" 
			{
				addNewAccomm();
				break;
			}
			case 2:		// "3.2  µî·Ï ¼÷¼Ò Á¶È¸"
			{
				searchRegisteredAccomm();
				break;
			}
			}
			break;
		}
		case 4:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				guestSearchAccomm();
				break;
			}
			case 2:
			{
				registReservation();
				break;
			}
			case 3:
			{
				opaqueReservation();
				break;
			}
			case 4:
			{
				myReservation();
				break;
			}
			}
			break;
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				changeUserSession();
				break;
			}
			case 2:
			{
				changeGuestSession();
				break;
			}
			}
			break;
		}
		case 7:
		{
			switch (menu_level_2)
			{
			case 1:
			{

				program_exit();
				is_program_exit = 1;
				break;;
			}
			}
			break;
		}

		return;
		}

	}

}


void SignUp()
{
	mainUI.signUp(in_fp, out_fp, &memberList);
}

void Withdrawal()
{
	withdrawalUI.withdrawal(in_fp, out_fp, &memberList);
}

void LogIn()
{
	mainUI.logIn(in_fp, out_fp, &memberList, &currentUser, &sessionList, &currentSession);
}

void LogOut()
{
	mainUI.logOut(in_fp, out_fp, &currentUser, &sessionList, &currentSession);
}

void changeUserSession()
{
	mainUI.changeSession(in_fp, out_fp, &memberList, &currentUser, &sessionList, &currentSession);
}

void changeGuestSession()
{
	fprintf(out_fp, "6.2. Gueset sessionÀ¸·Î º¯°æ\n");
	currentUser = NULL;
	currentSession = 0;
}

void program_error(int menu_level_1, int menu_level_2)
{
	fprintf(out_fp, "%d.%d. À¯È¿ÇÏÁö ¾ÊÀº ¸Þ´º ÀÔ·Â\n", menu_level_1, menu_level_2);
}

void addNewAccomm()
{
	addAccommUI.enterInfo(&session, in_fp, out_fp, &accommManager, &allAccommList);
}

void searchRegisteredAccomm() 
{

	hostSearchAccommUI.searchAccomms(&session, in_fp, out_fp, &accommManager, &allAccommList);

}

void myReservation(){
	myReservationUI.startUI(&session, in_fp, out_fp, &reservManager, &allReservList);
}
void guestSearchAccomm()
{
	guestSearchAccommUI.startUI(in_fp, out_fp, &accommManager, &allAccommList);
}

void registReservation(){
	reservAccommUI.startAddReservUI(&session, in_fp, out_fp, &reservManager, &allReservList, &allAccommList);
}
void opaqueReservation(){
	reservAccommUI.opqReservUI(&session, in_fp, out_fp, &reservManager, &allReservList, &allAccommList, &accommManager);
}

void program_exit()
{
	fprintf(out_fp, "7.1. Exit\n");
	fclose(in_fp);
	fclose(out_fp);
}