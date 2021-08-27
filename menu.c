#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include"structs.h"
#include"writeread.h"
#include"lovejeet.h"
#include"Srivishnu_headerfiles.h"
#include"sukhamfunctions.h"
#include"Utkarshfunction.h"
#include"rakshitfunctions.h"
#include"fahed.h"


//Functions for Displaying menu and partition
void display_menu(){
	printf("\n1.  Issue a book\n");
	printf("2.  Return a book\n");
	printf("3.  Display all issue records\n");
	printf("4.  Search records\n");
	printf("5.  Display all books\n");
	printf("6.  Display books by availaibility\n");
	printf("7.  Search books\n");
	printf("8.  Add book\n");
	printf("9.  Delete Book\n");
	printf("0.  Save and Quit\n");
}

void partition(){
	for(int i=0;i<146;i++){
		printf("-");
	}
}




int main(void)
{
	//Copying file's data to struct

	//opening file in read mode
	FILE* readbook;
	readbook = fopen("books.txt", "r");

	if(readbook == NULL)
	{
		FILE* temp;
		temp = fopen("books.txt", "a");
		fclose(temp);

		readbook = fopen("books.txt", "r");
	}

	//array of book type variables to store book and its info
	books book[5000];

	//reading data from file and storing it in array of structs
	int nb = numoflines(readbook);
	writetobs(book, nb, readbook);
	fclose(readbook);



	//reading issue records simlar to reading books
	FILE* readissue;
	readissue = fopen("issue.txt", "r");

	if(readissue == NULL){
		FILE* temp;
		temp = fopen("issue.txt", "a");
		fclose(temp);

		readbook = fopen("issue.txt", "r");
	}

	issuer irecord[5000];
	int ni = numoflines(readissue);
	writetois(irecord, ni, readissue);
	fclose(readissue);
	fine(irecord, ni);



	//The interface comes here

	printf("\n\n\nWELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n\n");

	display_menu();

	char s[200];
	while(1)
	{
		printf("\nType an option: ");
		scanf("%s%*c", s);

		//If the string is a valid one digit number then only it will select an option 
		if(strlen(s) == 1 && isdigit(s[0])) 
		{
			//converting to integer
			int o = atoi(s);


			//ADD ISSUER
			if(o == 1)
			{
				//TAKING STRINGS WITH SPACE
				char iname[100], iid[100];
				int bid, d, m, y;

				printf("\nGive issuer's name : ");
				scanf("%[^\n]%*c", iname);

				printf("Give issuer's roll number : ");
				scanf("%[^\n]%*c", iid);

				//LOWERING THE ISSUER ID BEFORE ADDING
				lower(iid);

				//CHECKING IF THE ROLL NUMBER IS ALREADY PRESENT AND HAS
				//ALREADY ISSUED A BOOK
				if(iidpresent(irecord, ni, iid))
				{
					printf("\n\nALREADY ISSUED ONE BOOK\n");
				}

				else
				{
					printf("Give book id : ");
					scanf("%d%*c", &bid);

					//CHECKING IF THE PARTICULAR BOOK IS AVAILABLE OR NOT
					if(!available(book, bid, &nb))
					{
						printf("\n\nBOOK NOT AVAILABLE\n");
					}
					else
					{
						date d;
						printf("Give issue date in format d m y : ");
						scanf("%d %d %d%*c", &d.d, &d.m, &d.y);

						//CHECKING IF THE DATE IS VALID
						if(validdate(d))
							addissuer(irecord, book, &ni, &nb, iname, iid, bid, d.d, d.m, d.y);
						else
							printf("\nDATE IS INVALID\n");
					}
				}

				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
			}


			//RETURN A BOOK
			else if(o == 2)
			{
				char iid[100]; int d, m, y;

				printf("\nGive the returner's Roll Number : ");
				scanf("%[^\n]%*c", iid);

				//CHECKING IF THE ROLL NUMBER IS THERE AND HE HAS NOT RETURNED ALREADY
				if(!ridpresent(irecord, iid, &ni))
				{
					printf("\n\nROLL NUMBER NOT PRESENT OR BOOK RETURNED ALREADY\n");
				}
				else
				{
					date d;
					printf("\nGive the return date in format d m y: ");
					scanf("%d %d %d%*c", &d.d, &d.m, &d.y);

					//CHECKING IF DATE IS VALID
					if(validdate(d))
					{
						//IT WILL CHECK IF THE RETURN DATE IS GREATER OR EQUAL THAN ISSUE BOOK
						//AND WILL DISPLAY FINE ALSO
						addreturndate(irecord, book, iid, &ni, &nb, d.d, d.m, d.y);
					}
					else
						printf("\nDATE IS INVALID\n");
				}

				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");

				fine(irecord, ni);
			}


			//DISPLAYING ALL BOOKS
			else if(o == 3)
			{
				Display_all_records(ni, irecord);
				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
			}


			//SEARCHING RECORDS IN DIFFERENT WAYS
			else if(o == 4)
			{
				
				printf("1. Search by Book Name\n");
				printf("2. Search by Book ID\n");
				printf("3. Search by Issue Date\n");
				printf("4. Search by Return Date\n");
				printf("5. Search by Issuer Name\n");
				printf("6. Search by Issuer Id\n");
				printf("7. Display returned books\n");
				printf("8. Display not returned books\n");
				printf("9. Display issue records between two dates\n");
				printf("0. Display total fine between two dates\n");				

				char ss[200];

				printf("\nGive option number : ");
				scanf("%s%*c", ss);

				if(strlen(ss) == 1 && isdigit(ss[0])) 
				{
					int k = atoi(ss);

					//IF YOU WRITE SOME INITIAL PART OF THE BOOK NAME, ISSUER NAME THEN 
					//ALL WILL DISPLAY CONTAINING THAT PART
					if(k == 1)
					{
						printf("Give the Book name: ");
						search_by_bookname(ni,irecord, nb , book);
					}
					else if(k == 2)
					{
						printf("Give the Book ID: ");
		 				search_by_book_id(ni, irecord);
					}
					else if(k == 3)
					{
						printf("\nGive the issue date in format d m y: ");
						search_by_issuedate(ni,irecord);
					}
					else if(k == 4)
					{
						printf("\nGive the return date in format d m y: ");
						search_by_returndate(ni,irecord);

					}
					else if(k == 5)
					{
						printf("Give the issuer name: ");
		 				search_by_issuername(ni, irecord);
					}
					else if(k == 6)
					{
						printf("Give the issuer ID: ");
						search_by_issuer_id(ni,irecord);

					}
					else if(k == 7)
					{
						returned_books(irecord,ni);

					}
					else if(k == 8)
					{
						not_returned_books(irecord,ni);

					}
					else if(k == 9)
					{
						date d1, d2;
						printf("\nGive first date in format d m y : ");
						scanf("%d %d %d%*c", &d1.d, &d1.m, &d1.y);

						printf("\nGive second date in format d m y : ");
						scanf("%d %d %d%*c", &d2.d, &d2.m, &d2.y);

						//CHECKING IF THE DATE IS VALID
						if(validdate(d1) && validdate(d2))
							display_issue_records_btw_dates(ni, irecord, d1, d2);
						else
							printf("\nDATE IS INVALID\n");
					}
					else if(k == 0)
					{
						date d1, d2;
						printf("\nGive first date in format d m y : ");
						scanf("%d %d %d%*c", &d1.d, &d1.m, &d1.y);

						printf("\nGive second date in format d m y : ");
						scanf("%d %d %d%*c", &d2.d, &d2.m, &d2.y);

						//CHECKING IF THE DATE IS VALID
						if(validdate(d1) && validdate(d2))
							printf("\nTotal fine between the above dates : %d" ,total_fine_btw_dates(ni, irecord, d1, d2));
						else
							printf("\nDATE IS INVALID\n");
					}
					else
					{
						printf("\nOPTION NOT VALID");
					}

				}
				else
				{
					printf("\nOPTION NOT VALID");
				}

				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");

			}



			else if(o == 5)
			{
				Display_all_books(nb, book);
				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
			}


			//DISPLAY AVAILABLE AND NON AVAILABLE BOOKS
			else if(o == 6)
			{
				printf("\n1. Display available books");
				printf("\n2. Display issued books\n\n");

				char ss[200];
				printf("\nGive option number : ");
				scanf("%s%*c", ss);

				if(strlen(ss) == 1 && isdigit(ss[0])) 
				{
					int g = atoi(ss);

					if(g == 1)
					{
						Search_by_availability(nb, book, "yes");
					}
					else if(g == 2)
					{
						Search_by_availability(nb, book, "no");
					}
					else{
						printf("\nOPTION NOT VALID");
					}
				}
				else
				{
					printf("\nOPTION NOT VALID");
				}

				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
			}



			//SEARCHING BOOKS IN DIFFERENT WAYS
			else if(o == 7)
			{

				printf("1. Search by Book Name\n");
				printf("2. Search by Author\n");
				printf("3. Search by Genre\n");
				printf("4. Search by Book ID\n");
				printf("5. Display no of copies by Book\n\n");

				char ss[200];
				printf("\nGive option number : ");
				scanf("%s%*c", ss);

				if(strlen(ss) == 1 && isdigit(ss[0])) 
				{
					int k = atoi(ss);

					if(k == 1)
					{
						printf("Give the book name: ");
						Search_by_name(nb, book);
					}
					else if(k == 2)
					{
						printf("Give the book author: ");
						Search_by_author(nb, book);
					}
					else if(k == 3)
					{
						printf("Give the book genre: ");
						Search_by_genre(nb, book);
					}
					else if(k == 4)
					{
						printf("Give the book id: ");
						Search_by_bookid(nb, book);
					}
					else if(k == 5)
					{
						printf("Give name of book:");
						no_of_books(nb, book);
					}
					else
					{
						printf("OPTION NOT VALID");
					}
				}

				else
				{
					printf("OPTION NOT VALID");
				}

				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
			}


			//ADD A BOOK
			else if(o == 8)
			{
				int bid; char bids[100]; char bname[100], bauthor[100], bgenre[100];

				printf("\nGive book ID : ");
				scanf("%s%*c", bids);

				//IT CHECKS IF BOOK ID GIVEN IS AN INTEGER OR NOT
				if(isnumpassed(bids))
				{
					bid = atoi(bids);
					if(!validbid(book, bid, &nb))
					{
						printf("\nBOOK ID EXISTS\n");

					}
					else
					{
						printf("Give the book name : ");
						scanf("%[^\n]%*c", bname);

						printf("Give the book author : ");
						scanf("%[^\n]%*c", bauthor);

						printf("Give the book genre : ");
						scanf("%[^\n]%*c", bgenre);

						addbook(book, &nb, bid, bname, bauthor, bgenre);
					}
					
				}

				else
				{
					printf("\nBOOK ID MUST BE AN INTEGER");
				}
				
				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
			}

			//THIS IS TO DELETE THE BOOK
			else if(o == 9)
			{
				int bid; char bids[100];
				printf("\nGive the bookid: ");

				scanf("%s%*c",bids);

				//CHECKING IF BOOK ID IS INTEGER OR NOT
				if(isnumpassed(bids))
				{
					bid = atoi(bids);
					if(available(book, bid, &nb))
					{
						delbookbyid(book, &nb, bid);
						printf("\nBOOK DELETED SUCCESSFULLY\n");
					}
					else
					{
						printf("\nBOOK NOT RETURNED OR NOT AVAILABLE\n");
					}

				}
				else
				{
					printf("\nBOOK ID MUST BE AN INTEGER");
				}

				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
			}

			//BREAKING THE LOOP IF O == 0
			else if(o == 0)
			{
				break;
			}

			else
			{

				printf("\nENTER VALID OPTION\n");
				printf("\n\n");
				partition();
				printf("\n\n");
				display_menu();
				printf("\n\n");
	
			}
		}

		else
		{
			printf("\nENTER VALID OPTION\n");
			printf("\n\n");
			partition();
			printf("\n\n");
			display_menu();
			printf("\n\n");
		}

	}

	fine(irecord, ni);



	//Saving all the data to the files
	FILE *writebook;
	writebook = fopen("books.txt", "w");

	writetobf(book, nb, writebook);

	fclose(writebook);


	FILE *writeissue;
	writeissue = fopen("issue.txt", "w");

	writetoif(irecord, ni, writeissue);

	fclose(writeissue);

}
