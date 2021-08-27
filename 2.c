#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include"structs.h"
#include"lovejeet.h"

//DELETES BOOK
void delbookbyid(books book[], int *nb, int bid)
{
	for(int i = 0; i < *nb; i++)
	{
		if(book[i].bid == bid)
		{
			strcpy(book[i].delete,"yes");
		}
	}
}

//IF THE BOOKID IS VALID I.E. IT IS UNIQUE
int validbid(books book[], int bid, int * nb)
{
	for(int i = 0; i < * nb; i++)
	{
		if(bid == book[i].bid)
			return 0;
	}
	return 1;
}

//IF ISSUER ID IS ALREADY PRESENT AND HE HASN'T RETURNED BOOK
int iidpresent(issuer irecord[], int ni, char * iid)
{
	for(int i = 0; i < ni; i++)
	{
		if(strcmp(irecord[i].iid, iid) == 0 && irecord[i].rdate.d == 0)
		{
			return 1;
		}
	}
	return 0;
}

int ridpresent(issuer irecord[], char* iid, int * ni)
{
	lower(iid);

	for(int i = 0; i < * ni; i++)
	{
		if(strcmp(iid, irecord[i].iid) == 0 && (irecord[i].rdate.d == 0))
			return 1;
	}
	return 0;
}

int available(books book[], int bid, int * nb)
{
	for(int i = 0; i < *nb; i++)
	{
		if(book[i].bid == bid)
		{
			if(strcmp(book[i].isavailable, "yes") == 0){
				return 1;
			}
			else{
				return 0;
			}
			break;
		}
	}
	return 0;
}