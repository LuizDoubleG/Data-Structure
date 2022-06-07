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

/*	================== printInstr =================

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
	fpData = fopen("filmes.txt", "r");
	if (!fpData)
	    printf("\aError opening input file\n"),
	           exit (110);
	while (fscanf(fpData, " %hd", &yearIn) != EOF)
	   {
	    pPic = (PICTURE*) malloc(sizeof(PICTURE));
	    if (!(pPic))
	        printf("\aOut of Memory in build list\n"),
	               exit (100);
	    pPic->year = yearIn;
	    printf("O ano do filme: %hd \n",pPic->year);

	    // Skip tabs and quote
	    while ((fgetc(fpData)) != '\t')
	       ;
	    while ((fgetc(fpData)) != '"')
	       ;
	    //fscanf(fpData, " %40[^\"], %*c", pPic->picture);
	    fscanf(fpData, " %40[^\"], %*c", pPic->picture);
	    printf("O nome do filme: %s \n",pPic->picture);

	    while ((fgetc(fpData)) != '\t')
	       ;
	    while ((fgetc(fpData)) != '"')
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

/*	=================== process ===================

/*	================== getChoice ==================

/*	================== printList ==================

/*	==================== search ====================

/*	==================== cmpYear ====================

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