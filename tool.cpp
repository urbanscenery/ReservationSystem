#include "tool.h"

int stoiDate(char* date){
	char year[5], month[3], day[3];
	int intDate = 0;
	for(int i = 0 ; i < 4 ; i++){
		year[i] = date[i];
	}
	year[4] = '\0';
	for(int i = 0 ; i < 2 ; i++){
		month[i] = date[i+5];
		day[i] = date[i+8];
	}	
	month[2] = '\0';
	day[2] = '\0';
	intDate += atoi(year)*10000;
	intDate += atoi(month)*100;
	intDate += atoi(day);
	return intDate;
}

int stoiTime(char* date){
	char hour[3], min[3];
	int intTime = 0;
	for(int i = 0 ; i < 2 ; i++){
		hour[i] = date[i+11];
		min[i] = date[i+14];
	}	
	hour[2] = '\0';
	min[2] = '\0';
	intTime += atoi(hour)*100;
	intTime += atoi(min);
	return intTime;
}

char* itoaDate(int date){
	char strDate[MAX_STRING];
	int year, month, day, temp1, temp2;
	year = date / 10000;
	month = (date / 100) % 100;
	day = date % 100;
	for(int i = 0 ; i < 4 ; i++){
		temp1 = year % 10;
		year = year / 10;
		strDate[3 - i] = temp1 + 48;
	}
	strDate[4] = ':';
	strDate[7] = ':';
	for(int i = 0 ; i < 2 ; i++){
		temp1 = month % 10;
		temp2 = day % 10;
		month = month / 10;
		day = day / 10;
		strDate[6 - i] = temp1 + 48;
		strDate[9 - i] = temp2 + 48;
	}
	strDate[10] = '\0';
	return strDate;
}