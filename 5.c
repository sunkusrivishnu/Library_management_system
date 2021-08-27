#include<stdio.h>
#include"structs.h"


//function for searching the issue records by issue date.

void search_by_issuedate(int ni, issuer issue_rec[])		
{
	int d,m,y;
	scanf("%d %d %d%*c",&d,&m,&y);		//taking the date as input d m y format.
	int count =0;
	for(int i = 0 ; i < ni ;i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( d == issue_rec[i].idate.d && m == issue_rec[i].idate.m && y == issue_rec[i].idate.y)		//comparing the input and issue date of each record.
		{
			//if date is matched then printing the record.
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname, issue_rec[i].iid, issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);
			count++;

		}
	}
	if(count==0)
    {
        printf("NO DATA FOUND\n");		//if none of the date in records match the input date.
    }

}

//function for searching the issue records by return date.

void search_by_returndate(int ni, issuer issue_rec[])
{
	int d,m,y;
	scanf("%d %d %d%*c",&d,&m,&y);			//taking the date as input d m y format.

	int count =0;
	for(int i = 0 ; i < ni ;i++ )
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( d == issue_rec[i].rdate.d && m == issue_rec[i].rdate.m && y == issue_rec[i].rdate.y)		//comparing the input and return date of each record.
		{
			//if date is matched then printing the record.
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname,issue_rec[i].iid,issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);
			count++;

		}
	}
	if(count == 0)
    {
		printf("NO DATA FOUND\n");		//if none of the date in records match the input date.
    }

}

//function for displaying the returned books.

void returned_books(issuer issue_rec[],int ni)	
{
	for(int i = 0 ; i < ni ; i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( issue_rec[i].rdate.d != 0 && issue_rec[i].rdate.m != 0 && issue_rec[i].rdate.y !=0)			//checking if return date of each record is present.
		{
			//if present printing the record.
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname,issue_rec[i].iid,issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);

		}
	}
}

//function for displaying the NOT returned books.

void not_returned_books(issuer issue_rec[],int ni)
{
	for(int i = 0 ; i < ni ; i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( issue_rec[i].rdate.d == 0 && issue_rec[i].rdate.m == 0 && issue_rec[i].rdate.y ==0)		//checking if return date of each record is present.
		{
			//if return date is not present then printing.
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname,issue_rec[i].iid,issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);

		}
	}
}
