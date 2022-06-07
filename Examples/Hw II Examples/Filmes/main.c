/*	This program maintains and displays a list of
	Academy Awards Motion Pictures.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <cType.h>
#include <stdbool.h>
#include "linkListADT.h"

/*	Data Structure for Academy Awards
	   Written by:
	   Date:
*/
//const short STR_MAX = 41;
#define STR_MAX 41

typedef struct{
	 short   year;
	 char    picture [STR_MAX];
	 char    director[STR_MAX];
} PICTURE;

//	Prototype Declarations - Application Functions
	void  printInstr (void);
	LIST* buildList  (void);
	void  process    (LIST* list);
	char  getChoice  (void);
	void  printList  (LIST* list);
	void  search     (LIST* list);
	int   cmpYear    (void* pYear1, void* pYear2);

int main (void)
{
//	Local Definitions
	LIST* list;

//	Statements
	printInstr ();
	list = buildList ();
	process (list);

	printf("End Best Pictures\n"
	       "Hope you found your favorite!\n");
	return 0;
}	// main

/*	================== printInstr =================	Print instructions to user.	   Pre    nothing	   Post   instructions printed*/void printInstr (void){//	Statements	printf("This program prints the Academy Awards \n"	  "Best Picture of the Year and its director.\n"	  "Your job is to enter the year; we will do\n"	  "the rest. Enjoy.\n");	return;}	// instr

/*	==================== buildList ====================
	Reads a text data file and loads the linked list
	Pre    file exists in format: yy \t 'pic' \t 'dir'
	Post   list contains data
	       -or- program aborted if problems
*/
LIST* buildList (void)
{
//	Local Definitions
	FILE* fpData;
	LIST* list;

	short  yearIn;
	int    addResult;

	PICTURE* pPic;
	char c;

//	Statements
	list   = createList (cmpYear);
	if (!list)
	    printf("\aCannot create list\n"),
	           exit (100);
	fpData = fopen("pictures.dat", "r");
	if (!fpData)
	    printf("\aError opening input file\n"),
	           exit (110);
	while (fscanf(fpData, " %hd", &yearIn) == 1)
	   {
	    pPic = (PICTURE*) malloc(sizeof(PICTURE));
	    if (!(pPic))
	        printf("\aOut of Memory in build list\n"),
	               exit (100);
	    pPic->year = yearIn;
	    printf("O ano do filme: %hd \n",pPic->year);

	    // Skip tabs and quote
	    while ((fgetc(fpData)) == '\t')
	       ;
	    while ((fgetc(fpData)) == '"')
	       ;
	    //fscanf(fpData, " %40[^\"], %*c", pPic->picture);
	    fscanf(fpData, " %40[^\"], %*c", pPic->picture);
	    printf("O nome do filme: %s \n",pPic->picture);

	    while ((fgetc(fpData)) == '\t')
	       ;
	    while ((fgetc(fpData)) == '"')
	       ;
	    //fscanf(fpData, " %40[^\"], %*c", pPic->director);
	    fscanf(fpData, " %40[^\"], %*c", pPic->director);
	    printf("O nome do diretor: %s \n",pPic->director);
        //scanf("%c",&c);
	    // Insert into list
	    addResult = addNode (list, pPic);
	    if (addResult != 0)
	        if (addResult == -1)
	            printf("Memory overflow adding movie\a\n"),
	                    exit (120);
	        else
	            printf("Duplicate year %hd not added\n\a",
	                    pPic->year);
	    while (fgetc(fpData) == '\n')
	       ;
	   } // while
	return list;
}	// buildList

/*	=================== process ===================	Process user choices	Pre    list has been created	Post   all of user's choice executed*/void process (LIST* list){//	Local Definitions	char choice;//	Statements	do	   {	    choice = getChoice ();	    switch (choice)	       {	        case 'P': printList (list);	                  break;	        case 'S': search (list);	        case 'Q': break;	       } // switch	   } while (choice != 'Q');	return;}	// process

/*	================== getChoice ==================	Prints the menu of choices.	   Pre    nothing	   Post   menu printed and choice returned*/char getChoice (void){//	Local Definitions	char choice;	bool valid;//	Statements	printf("======== MENU ======= \n"	       "Here are your choices:\n"	       "  S: Search for a year\n"	       "  P: Print all years  \n"	       "  Q: Quit             \n\n"	       "Enter your choice: ");	do	   {	    scanf(" %c", &choice);	    choice = toupper(choice);	    switch (choice)	       {	        case 'S':	        case 'P':	        case 'Q': valid = true;	                  break;	        default:  valid = false;	                  printf("\aInvalid choice\n"	                         "Please try again: ");	                  break;	       } // switch	   } while (!valid);	return choice;}	// getChoice

/*	================== printList ==================	Prints the entire list	   Pre    list has been created	   Post   list printed*/void printList(LIST* list){//	Local Definitions	PICTURE* pPic;//	Statements	// Get first node	if (listCount (list) == 0)	   printf("Sorry, nothing in list\n\a");	else	   {	    printf("\nBest Pictures List\n");	    traverse (list, 0, (void**)&pPic);	    do	      {	       printf("%hd %-40s %s\n",	              pPic->year,      pPic->picture,	              pPic->director);	      } while (traverse (list, 1, (void**)&pPic));	   } // else	printf("End of Best Pictures List\n\n");}	// printList

/*	==================== search ====================	Searches for year and prints year, picture, and	director.	   Pre    list has been created	          user has selected search option	   Post   year printed or error message*/void search (LIST* list){//	Local Definitions	short    year;	bool     found;	PICTURE  pSrchArgu;	PICTURE* pPic;//	Statements	printf("Enter a four digit year: ");	scanf ("%hd", &year);	pSrchArgu.year = year;	found = searchList (list, &pSrchArgu,	                    (void**)&pPic);	if (found)	    printf("%hd %-40s %s\n",	            pPic->year, pPic->picture, pPic->director);	else	    printf("Sorry, but %d is not available.\n", year);	return;}	// search

/*	==================== cmpYear ====================	Compares two years in PICTURE structures	   Pre  year1 is a pointer to the first structure	        year2 is a pointer to the second structure	   Post two years compared and result returned	Return -1 if year1 less; 0 if equal; +1 greater*/int cmpYear (void* pYear1, void* pYear2){//	Local Definitions	int   result;	short year1;	short year2;//	Statements	year1 = ((PICTURE*)pYear1)->year;	year2 = ((PICTURE*)pYear2)->year;	if (year1 < year2)	    result = -1;	else if (year1 > year2)	    result = +1;	else	    result = 0;	return result;}	// cmpYear

/* Results:
This program will print the Academy Awards
Best Picture of the Year and its director.
Your job is to enter the year;  we will do
the rest. Enjoy.
Duplicate year 1942 not added
======== MENU =======
Here are your choices:
  S: Search for a year
  P: Print all years
  Q: Quit

Enter your choice: p

Best Pictures List
1932 Cavalcade                                Frank Lloyd
1934 It Happened One Night                    Frank Capra
1938 You Can't Take It With You               Frank Capra
1939 Gone With the Wind                       Victor Fleming
1941 How Green Was My Valley                  John Ford
1942 Mrs. Miniver                             William Wyler
1943 Casablanca                               Michael Curtiz
1945 The Lost Weekend                         William Wyler
1946 The Best Years of Our Lives              William Wyler
1947 Gentleman's Agreement                    Elia Kazan
1950 All About Eve                            Joseph L. Mankiewicz
1953 From Here To Eternity                    Fred Zinnemann
End of Best Pictures List

======== MENU =======
Here are your choices:
  S: Search for a year
  P: Print all years
  Q: Quit

Enter your choice: s
Enter a four digit year: 1946
1946 The Best Years of Our Lives              William Wyler
======== MENU =======
Here are your choices:
  S: Search for a year
  P: Print all years
  Q: Quit

Enter your choice: q
End Best Pictures
Hope you found your favorite!
*/
