#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structs.h"



void stringlower(char *s1)                        // Functions which makes the upper case to lower case.
{
    for (int j = 0;j < strlen(s1) ;j++)
	{
		if (s1[j] >= 'A' && s1[j] <= 'Z')         // Converting the lower case characters into upper case using ASCII values.
		{
			s1[j] = s1[j] + 32;
		}
	}
}

int stringcompare(char *s1, char *s2)           // Functions for comparing characters to two strings using this fn in search functions.
{
    if (strlen(s1) <= strlen(s2))               
    {
        for (int i = 0;i < strlen(s1);i++)
        {
            if (s1[i] != s2[i])                 // If the comparing characters are not equal then it returns 1 and breaks out of loop.
            {
                return 1;
            }
        }
        return 0;                               // Returning 0 if the characters are same.
    }
    return 1;
}

void Search_by_name(int nb,books book[])       // Function for searching books by name.
{
    char bookname[140];
	scanf("%[^\n]%*c",bookname);               // Taking input including spaces.
    stringlower(bookname);                     // If they are any upper case characters it converts into lower case characters.
    int count =0;

    for (int i = 0;i < nb;i++)
	{
        if (i == 0)
        {
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n\n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY\n");
        }
        if (strcmp(book[i].delete,"no") == 0)   // Condition if the books is not there in list.
        {
            // Comparing bookname with the book name.
            if (stringcompare(bookname,book[i].bname) == 0 )
                {
                    printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
    		        printf("\n");
                    count++;
                }
        }
    }
    if(count==0)                            // If the book with that name is not there then  it shows the given statement.
    {
        printf("NO DATA FOUND\n");
    }
}

void Search_by_author(int nb,books book[])
{
    char bookauthor[140];
	scanf("%[^\n]%*c",bookauthor);          // Taking input with spaces.
    stringlower(bookauthor);
    int count =0;

    for (int i = 0;i < nb;i++)              // Running loop for searching the book.
	{
        if (i == 0)
        {
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n\n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        }
        if (strcmp(book[i].delete,"no") == 0) // Using pre defined strcmp for comparing the while string. 
        {
            if (stringcompare(bookauthor,book[i].bauthor) == 0 ) // Comparing the given input with the book  author.
            {
                printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
		        printf("\n");
                count++;
            }
        }
    }
    if(count==0)                            // If the book is not found then the given statement is diaplayed.
    {
        printf("NO DATA FOUND\n");
    }
}

void Search_by_genre(int nb,books book[])   // Functions for searching with genre.
{
    char bookgenre[140];
	scanf("%[^\n]%*c",bookgenre);           // Taking input with spaces.
    stringlower(bookgenre);
    int count =0;

    for (int i = 0;i < nb;i++)              // Running loop for searching books.
	{
        if (i == 0)
        {   // Printing the headings for respective columns.
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n\n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        }
        if (strcmp(book[i].delete,"no") == 0)
        {
            if (stringcompare(bookgenre,book[i].bgenre) == 0 )
            {   
                // Comparing string and displaying the result. 
                printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
		        printf("\n");
                count++;
            }
        }
    }
    if(count==0)                            // If the given book with given feature is not found then it shows the given statement.
    {
        printf("NO DATA FOUND\n");
    }
}

void Search_by_availability(int nb,books book[], char *bookavailability)    // Function for searching with the help of availability.
{
    stringlower(bookavailability);
    for (int i = 0;i < nb;i++)
	{
        if (i == 0)
        {
            // Statement for displaying headings with respective columns.
            printf("\n\n%-10s %-30s %-30s %-20s \n\n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE");
        }
        if (strcmp(book[i].delete,"no") == 0)
        {
            if (strcmp(bookavailability,book[i].isavailable) == 0)
            {
                // If the condition is true then it displays the output .
                printf("%-10d %-30s %-30s %-20s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre);
		        printf("\n");
            }
        }
    }
}

void Search_by_bookid(int nb, books book[])         // Functions for searching with the help of book id.
{
    int bookid;
    scanf("%d%*c",&bookid);
    int count =0;

    for (int i = 0;i < nb;i++)                      // Running loop for searching.
	{
        if (i == 0)
        {
            // Displaying headings for the respective columns.
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n\n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        }
        if (strcmp(book[i].delete,"no") == 0)       // If the book is deleted then it is not displayed.
        {
            if (bookid == book[i].bid)              // If the condition is displayed then the output is displayed. 
            {
                printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
		        printf("\n");
                count++;

            }
        }
    }
    if(count==0)                                    // If the book is not found then the output is not displayed.
    {
        printf("NO DATA FOUND\n");
    }
}

void Display_all_records(int ni, issuer irecord[])  /// Functions for displaying all the records.  
{
    for (int i = 0; i < ni; i++)
    {
        if (i == 0)
        {
            // Printing headings for the respective headings for columns.
            printf("\n\n%-25s %-15s %-8s %-30s %-8s %-16s %-20s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","FINE","ISSUE DATE","RETURN DATE");
        }
        if (irecord[i].idate.d < 10 && irecord[i].idate.m < 10)
        {
            printf("%-25s %-15s %-8d %-30s %-5d % 5d-0%d-%d %8d-%d-%-15d \n",irecord[i].iname,irecord[i].iid,irecord[i].bid,irecord[i].bname,irecord[i].fine,irecord[i].idate.d,irecord[i].idate.m,irecord[i].idate.y,irecord[i].rdate.d,irecord[i].rdate.m,irecord[i].rdate.y);
        }
        if (irecord[i].idate.d < 10 && irecord[i].idate.m >= 10)
        {
            printf("%-25s %-15s %-8d %-30s %-5d % 5d-%d-%d %8d-%d-%-15d \n",irecord[i].iname,irecord[i].iid,irecord[i].bid,irecord[i].bname,irecord[i].fine,irecord[i].idate.d,irecord[i].idate.m,irecord[i].idate.y,irecord[i].rdate.d,irecord[i].rdate.m,irecord[i].rdate.y);
        }
        if (irecord[i].idate.d >= 10 && irecord[i].idate.m < 10)
        {
            printf("%-25s %-15s %-8d %-30s %-5d %5d-0%d-%d %8d-%d-%-15d \n",irecord[i].iname,irecord[i].iid,irecord[i].bid,irecord[i].bname,irecord[i].fine,irecord[i].idate.d,irecord[i].idate.m,irecord[i].idate.y,irecord[i].rdate.d,irecord[i].rdate.m,irecord[i].rdate.y);
        }
        if (irecord[i].idate.d >= 10 && irecord[i].idate.m >= 10)
        {
            printf("%-25s %-15s %-8d %-30s %-5d %5d-%d-%d %8d-%d-%-15d \n",irecord[i].iname,irecord[i].iid,irecord[i].bid,irecord[i].bname,irecord[i].fine,irecord[i].idate.d,irecord[i].idate.m,irecord[i].idate.y,irecord[i].rdate.d,irecord[i].rdate.m,irecord[i].rdate.y);
        }
        // The above conditions for alining the dates into columns correctly.
    }
    printf("\n");
}
