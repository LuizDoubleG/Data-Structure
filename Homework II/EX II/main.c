/*	This program parses lines to checks the match of Square Bracket {}, Curly Brackets [] and Parentheses () in text files.
	    Written by: LuizDoubleG
	    Date: 04/06/2022
*/

#include <stdio.h>
#include "fileParser.h"
#define MAX_FILE_NAME 25

int main (void){
// Local Definitions
    FILE* fPtr;
    char fileID[MAX_FILE_NAME];

//	Statements
    // Ask user for file name
    printf ("Enter the file name for file to be parsed: ");
    scanf("%s", fileID);

    // Open file
    fPtr = fopen(fileID, "r");
    if (fPtr == NULL){
        printf("File '%s' could not be opened.\n", fileID);
        return 100;
    } // if

    // Parse file and check for errors 
    parseFile(fPtr);

    return 0;
} // main