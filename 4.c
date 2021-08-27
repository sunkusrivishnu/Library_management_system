#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "lovejeet.h"

//CONVERTING THE STRING CHARACTERS TO LOWERCASE
void string_lower(char *s1)
{
        for (int j = 0; j < strlen(s1); j++)
        {
                if (s1[j] >= 'A' && s1[j] <= 'Z')
                {
                        s1[j] = s1[j] + 32;
                }
        }
}

//COUNT NUMBER OF COPIES OF A BOOK
void no_of_books(int nb, books book[]){
        int book_count=0;
        char bookname[150];


        scanf("%[^\n]%*c",bookname);
        string_lower(bookname);

        for(int i=0; i<nb; i++) {

                if(strcmp(bookname,book[i].bname)==0) {
                        book_count+=1;

                }
        }

        printf("\n\n%s : %d\n",bookname,book_count);
}
void swap(int *xp, int *yp)
{
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
        int i, j;
        for (i = 0; i < n-1; i++)

                // Last i elements are already in place
                for (j = 0; j < n-i-1; j++)
                        if (arr[j] > arr[j+1])
                                swap(&arr[j], &arr[j+1]);
}

//DISPLAY ALL BOOKS IN A SORTED WAY
void Display_all_books(int nb, books book[])
{
        int arr[nb];
        for(int j=0; j<nb; j++) {
                arr[j]=book[j].bid;

        }

        bubbleSort(arr,nb);
        printf("\n\n%-10s %-30s %-30s %-20s %-5s \n\n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        for (int i = 0; i < nb; i++)
        {
                for(int j=0; j<nb; j++)
                {
                        //IF THE RECORD IS TO BE DELETED THEN IT WON'T SHOW THAT RECORD
                        if (arr[i]==book[j].bid && strcmp(book[j].delete,"no") == 0)
                        {
                                printf("%-10d %-30s %-30s %-20s %-5s ",book[j].bid,book[j].bname,book[j].bauthor,book[j].bgenre,book[j].isavailable);
                                printf("\n");
                        }

                }

        }
}

//IT DISPLAYS RECORDS OF BOOKS ISSUED BETWEEN TWO DATES
void display_issue_records_btw_dates(int ni, issuer irecord[], date d1, date d2)
{
    date dmax, dmin;
    if(first_date_greater_than_second(d1, d2)){
        dmax = d1; dmin = d2;
    }
    else{
        dmax = d2; dmin = d1;
    }

    printf("\n\n%-25s %-15s %-8s %-30s %-8s %-16s %-20s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","FINE","ISSUE DATE","RETURN DATE");
    for(int i = 0; i < ni; i++)
    {
        if(first_date_greater_than_second(irecord[i].idate, dmin) && first_date_greater_than_second(dmax, irecord[i].idate))
        {
            printf("%-25s %-15s %-8d %-30s %-5d % 5d-%d-%d %8d-%d-%-15d \n",irecord[i].iname,irecord[i].iid,irecord[i].bid,irecord[i].bname,irecord[i].fine,irecord[i].idate.d,irecord[i].idate.m,irecord[i].idate.y,irecord[i].rdate.d,irecord[i].rdate.m,irecord[i].rdate.y);
        }
    }
}

//TOTAL FINE FOR BOOKS RETURNED BETWEEN TWO DATES
int total_fine_btw_dates(int ni, issuer irecord[], date d1, date d2)
{
    int tfine = 0;

    date dmax, dmin;
    if(first_date_greater_than_second(d1, d2))
    {
        dmax = d1; dmin = d2;
    }
    else
    {
        dmax = d2; dmin = d1;
    }

    for(int i = 0; i < ni; i++)
    {
        if(irecord[i].rdate.d != 0)
        {
            if(first_date_greater_than_second(irecord[i].rdate, dmin) && first_date_greater_than_second(dmax, irecord[i].rdate))
            {
                tfine += irecord[i].fine;
            }
        }
    }

    return tfine;

}

