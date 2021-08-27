#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include"structs.h"


//function to count the no.of lines in the records.

int numoflines(FILE* ftor)
{
	fseek(ftor, 0, 0);
	int count = 0;
	char c;
	while((c = fgetc(ftor)) != EOF)		//while character does not reach the end of file.
	{
		if(c == '\n')		//if character encounters '\n' .
		{
			count++;		//incrementing the count.
		}
	}
	fseek(ftor, 0, 0);
	return count;
}

//function to read from book records file and putting into structures

void writetobs(books book[], int n, FILE* readbook)
{
	fseek(readbook, 0, 0);
	for(int i = 0; i < n; i++)
	{
		//reading from book records file using fscanf and writing into structures of book array of structures.

		fscanf(readbook, "bookid=>%d||bookname=>%[^|]||bookauthor=>%[^|]||bookgenre=>%[^|]||isavailable=>%[^|]||delete=>%s%*c",
			&book[i].bid, book[i].bname, book[i].bauthor, book[i].bgenre, book[i].isavailable, book[i].delete);
	}
	fseek(readbook, 0, 0);
}

//function to read from the structures and putting into book records file. 

void writetobf(books book[], int n, FILE* writebook)
{
	fseek(writebook, 0, 0);
	for(int i = 0; i < n; i++)
	{
		if(strcmp(book[i].delete, "yes") == 0)		//checking if record needs to be deleted from the record.
			continue;				//not adding into file if needs to be deleted.
				
		//adding to file using fprintf.

		fprintf(writebook, "bookid=>%d||bookname=>%s||bookauthor=>%s||bookgenre=>%s||isavailable=>%s||delete=>%s\n",
			book[i].bid, book[i].bname, book[i].bauthor, book[i].bgenre, book[i].isavailable, book[i].delete);
	}
	fseek(writebook, 0, 0);
}

//function to read from issue records file and putting into structure.

void writetois(issuer irecord[], int n, FILE* readissue)
{
	fseek(readissue, 0, 0);
	for(int i = 0; i < n; i++)
	{

		//reading from issue records file using fscanf and writing into structures of irecord array of structures.

		fscanf(readissue, "issuername=>%[^|]||issuerid=>%[^|]||bookname=>%[^|]||bookid=>%d||issuedate=>%d/%d/%d||returndate=>%d/%d/%d||fine=>%d%*c",
			irecord[i].iname, irecord[i].iid, irecord[i].bname, &irecord[i].bid, &irecord[i].idate.d, &irecord[i].idate.m, &irecord[i].idate.y, 
			&irecord[i].rdate.d, &irecord[i].rdate.m, &irecord[i].rdate.y, &irecord[i].fine);
	}
	fseek(readissue, 0, 0);
}

//function to read from the structures and putting into issue records file.

void writetoif(issuer irecord[], int n, FILE* writeissue)
{
	fseek(writeissue, 0, 0);
	for(int i = 0; i < n; i++)
	{
		//adding to issue records file using fprintf.

		fprintf(writeissue, "issuername=>%s||issuerid=>%s||bookname=>%s||bookid=>%d||issuedate=>%d/%d/%d||returndate=>%d/%d/%d||fine=>%d\n",
			irecord[i].iname, irecord[i].iid, irecord[i].bname, irecord[i].bid, irecord[i].idate.d, irecord[i].idate.m, irecord[i].idate.y, 
			irecord[i].rdate.d, irecord[i].rdate.m, irecord[i].rdate.y, irecord[i].fine);
	}
	fseek(writeissue, 0, 0);
}

