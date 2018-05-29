#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>

#include "main.h"
#include "AccommManager.h"
#include "GuestSearchAccommUI.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
void addNewAccomm();
void searchRegisteredAccomm();
void program_exit();

FILE* in_fp, *out_fp;

void searchAccomm(Session session, FILE* in_fp, FILE* out_fp);

char* Session::getUserID(){
	return this->userID;
}

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
	Session ses1("test");
	while (!is_program_exit)
	{
		// ÀÔ·ÂÆÄÀÏ¿¡¼­ ¸Þ´º ¼ýÀÚ 2°³¸¦ ÀÐ±â
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		// ¸Þ´º ±¸ºÐ ¹× ÇØ´ç ¿¬»ê ¼öÇà
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1:   // "1.1. È¸¿ø°¡ÀÔ" ¸Þ´º ºÎºÐ
			{
				// join() ÇÔ¼ö¿¡¼­ ÇØ´ç ±â´É ¼öÇà
				//join();
				break;
			}
			case 2:	 // "1.2. È¸¿øÅ»Åð" ¸Þ´º ºÎºÐ
			{

				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			}
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				break;
			}
			case 2:
			{
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
				searchAccomm(ses1, in_fp, out_fp);
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				break;
			}
			}
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

void searchAccomm(Session session, FILE* in_fp, FILE* out_fp)
{
	GuestSearchAccommUI ui;
	ui.startUI(session, in_fp, out_fp);
	/*
	char city[MAX_STRING], date[MAX_STRING];
	fscanf(in_fp, "%s %s", city, date);
	char id[MAX_STRING];
	strcpy(id, session.getUserID());
	printf("%s %s %s\n", city, date, id);
	fprintf(out_fp, "4.1 숙소검색\n");
	fprintf(out_fp, "%s %s %s\n", city, date, id);
	*/
	AccommList* alist = new AccommList();
	alist -> insertNode("a", "daegu", 10000, 20170101, 100000);
	alist -> insertNode("b", "daegu", 10000, 20170101, 100000);
	alist -> insertNode("c", "asdfsdf", 10000, 20170101, 100000);
	AccommList* newlist = alist -> searchAccomm("daegu", 20170101);
	newlist -> displayAccommList();
	return;
}


void program_exit()
{
	fprintf(out_fp, "7.1. Á¾·á\n");
	fclose(in_fp);
	fclose(out_fp);
}