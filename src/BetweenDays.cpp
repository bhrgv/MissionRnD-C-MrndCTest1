/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int* getDate(struct node* dateHead)
{
	int flg = 0;
	int date[8],i=0;
	while (dateHead)
	{
		date[i] = dateHead->data;
		dateHead->next;
	}
	int dd = date[0] * 10 + date[1];
	int mm = date[2] * 10 + date[3];
	int yy = date[4] * 1000 + 100*date[5]+10*date[6]+date[7];
	int* dateRes = (int*)malloc(3 * sizeof(int));
	dateRes[0] = dd;
	dateRes[1] = mm;
	dateRes[2] = yy;
	return dateRes;
}
int leapYear(int yy)
{
	if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0))
		return 1;
	return 0;
}
int getNumberDays(int mm,int yy)
{
	switch (mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		if (leapYear(yy))
			return 29;
		else
			return 28;
	default:
		return 30;
	}
}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int* date1 = getDate(date1head);
	int* date2 = getDate(date2head);
	if (date1[1] == date2[1] && date1[2] == date2[2])
	{
		if (date1[0] == date2[0] || abs(date1[0] - date2[0]) == 1)
			return 1;
	}
	int days = 0,i;
	if (date2[2] > date1[2])
	{
		
	}
	for (i = date1[2] + 1; i < date2[2]; i++)
	{
		if (leapYear(i))
			days += 366;
		else
			days += 365;
	}
	for (i = date1[1]; i<12; i++)
	{
		days += getNumberDays(i, date1[2]);
	}
	for (i = 1; i<date2[1]; i++)
	{
		days += getNumberDays(i, date2[2]);
	}
	for (i = date1[0] + 1; i <= getNumberDays(date1[1], date1[2]); i++)
	{
		days += 1;
	}
	for (i = 1; i < date2[0]; i++)
	{
		days += 1;
	}
}