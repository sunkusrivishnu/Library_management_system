#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include"structs.h"
#include"lovejeet.h"

//CHECKS IF THE GIVEN STRING IS POSITIVE INTEGER(INCLUDING 0) OR NOT
int isnumpassed(char *n)
{
	for(int i = 0; i < strlen(n); i++)
	{
		//isdigit returns 0 when it gets a non numeric character
		if(isdigit(n[i]) == 0)
			return 0;
	}
	return 1;
}


//LOWERS THE STRING
void lower(char * st)
{
	for(int i = 0; i < strlen(st); i++)
	{
		st[i] = tolower(st[i]);
	}
}


//FUNCTION TO ADD BOOK
void addbook(books book[], int * nb, int bid, char* bname, char* bauthor, char* bgenre)
{
	lower(bname);
	lower(bauthor);
	lower(bgenre);

	book[*nb].bid = bid;
	strcpy(book[*nb].bname , bname);
	strcpy(book[*nb].bauthor , bauthor);
	strcpy(book[*nb].bgenre , bgenre);
	strcpy(book[*nb].isavailable , "yes");
	strcpy(book[*nb].delete , "no");

	*nb += 1;
}

//ADDS ISSUER
void addissuer(issuer irecord[], books book[], int * ni, int * nb, char * iname, char*iid, int bid, int d, int m, int y)
{
	lower(iname);
	lower(iid);

	strcpy(irecord[*ni].iname , iname);
	strcpy(irecord[*ni].iid , iid);
	irecord[*ni].bid = bid;

	for(int i = 0; i < *nb; i++)
	{
		if(book[i].bid == bid){
			strcpy(irecord[*ni].bname , book[i].bname);
			strcpy(book[i].isavailable, "no");
			break;
		}
	}

	irecord[*ni].idate.d = d;
	irecord[*ni].idate.m = m;
	irecord[*ni].idate.y = y;

	irecord[*ni].rdate.d = 0;
	irecord[*ni].rdate.m = 0;
	irecord[*ni].rdate.m = 0;

	irecord[*ni].fine = 0;

	*ni += 1;
}

//ADD RETURN DATE I.E. RETURNING A BOOK
void addreturndate(issuer irecord[], books book[], char* iid, int *ni, int *nb, int d, int m, int y)
{
	lower(iid);

	date re_date;
	re_date.d = d; re_date.m = m; re_date.y = y; 

	int i = 0;
	for(i = 0; i < *ni; i++)
	{
		if(strcmp(irecord[i].iid, iid) == 0 && irecord[i].rdate.d == 0)
		{
			if(first_date_greater_than_second(irecord[i].idate, re_date))
			{
				printf("\nISSUE DATE SHOULD NOT BE AFTER RETURN DATE\n");
			}
			else
			{
				irecord[i].rdate.d = d;
				irecord[i].rdate.m = m;
				irecord[i].rdate.y = y;

				for(int j = 0; j < *nb; j++)
				{
					if(irecord[i].bid == book[j].bid)
					{
						strcpy(book[j].isavailable, "yes");
						break;
					}
				}
			}
			break;
		}
	}

	printf("\nFine : %d\n", fineonsingle(irecord[i]));
}



//////////////////
//FINE FUNCTIONS//
//////////////////


//IT CHECKS IF A YEAR IS LEAP YEAR OR NOT
int isleapyear(int y)
{
	return (y % 100 != 0)? !(y%4) : !(y%400);
}

//RETURNS A DATE THAT IS TWO WEEKS AFTER THE GIVEN THAT 
date aftertwoweek(date idate)
{
	date res = idate;
	if(idate.m == 1 || idate.m == 3 || idate.m == 5 || idate.m == 7 || idate.m == 8|| idate.m == 10 || idate.m == 12){
		res.d += 14;
		if(res.d > 31)
		{
			res.d = res.d % 31;
			res.m += 1;
		}
	}

	else if(idate.m == 2){
		res.d += 14;
		if(isleapyear(idate.y)){
			if(res.d > 29)
			{
				res.d = res.d % 29;
				res.m += 1;
			}
		}
		else{
			if(res.d > 28)
			{
				res.d = res.d % 28;
				res.m += 1;
			}

		}
	}

	else
	{
		res.d += 14;
		if(res.d > 30)
		{
			res.d = res.d % 30;
			res.m += 1;
		}
	}


	if(res.m == 13){
		res.m = 1;
		res.y += 1;
	}

	return res;
}

//DAYS UPTO A CERTAIN DATE(USED IN FINE)
int daysupto(date d)
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(isleapyear(d.y))
	{
		months[1] = 29;
	}

	int res = 0;

	for(int i = 0; i < d.m - 1; i++)
	{
		res += months[i];
	}

	res += d.d;

	return res;
}

//GIVES DAYS BETWEEN TWO DATES
int daysbwdates(date d1, date d2)
{
	int yearsbw[100] = {0};
	int daysbw = 0;
	int y1 = d1.y;
	int n = d2.y - d1.y + 1;

	daysbw -= daysupto(d1);

	for(int i = 0; i < n-1 ; i++)
	{
		yearsbw[i] = y1;

		if(isleapyear(yearsbw[i]))
			daysbw += 366;
		else
			daysbw += 365;

		y1++;
	}

	daysbw += daysupto(d2);
	return daysbw;

}

//USED TO COMPARE TWO DATES
int first_date_greater_than_second(date d1, date d2)
{
	if(d2.y < d1.y)
	{
		return 1;
	}
	else if(d2.m < d1.m && d2.y == d1.y)
	{
		return 1;
	}

	else if (d2.d < d1.d && d2.m == d1.m && d2.y == d1.y)
	{
		return 1;
	}
	return 0;
}

//GIVES FINE TO ALL RECORDS IF THE BOOK IS RETURNED
void fine(issuer irecord[], int ni)
{
	for(int i = 0; i < ni; i++)
	{
		if(irecord[i].idate.d == 0){
			continue;
		}

		else
		{
			date schdate = aftertwoweek(irecord[i].idate);

			if(first_date_greater_than_second(irecord[i].rdate, schdate))
			{
				irecord[i].fine = daysbwdates(schdate, irecord[i].rdate)*15;
			}

			else
			{
				irecord[i].fine = 0;
			}
		}
	}
}

//WILL GIVE AMOUNT OF FINE ON A SINGLE RECORD
int fineonsingle(issuer record)
{
		if(record.idate.d == 0){
			return 0;
		}

		else
		{
			date schdate = aftertwoweek(record.idate);

			if(first_date_greater_than_second(record.rdate, schdate))
			{
				record.fine = daysbwdates(schdate, record.rdate)*15;
			}
			else
			{
				record.fine = 0;
			}
		}

		return record.fine;
}

//CHECKS IF A DATE IS VALID OR NOT
int validdate(date d)
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(d.y == 0)
		return 0;

	if(d.m > 12 || d.m < 1)
		return 0;

	if(d.m != 2)
	{
		if(d.d == 0 || d.d > months[d.m-1])
			return 0;
	}
	else
	{
		if(isleapyear(d.y))
		{
			if(d.d == 0 || d.d > 29)
				return 0;
		}
		else
		{
			if(d.d == 0 || d.d > 28)
				return 0;
		}
	}

	return 1;
}
