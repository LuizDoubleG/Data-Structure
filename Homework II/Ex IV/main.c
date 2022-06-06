/*	Classifies text file words by its inicial letter, then print how many words are in each letter.
	   Written by: LuizDoubleG
	   Date: 05 06 2022
*/

#include <stdio.h>
#include "wordClassifier.h"
#define MAX_FILE_NAME 25

int main (void){
// Local Definitions
    FILE* fPtr;
    char fileID[MAX_FILE_NAME];

//	Statements
    // Ask user for file name
    printf ("Enter the file name for file to have its words classified: ");
    scanf("%s", fileID);

    // Open file
    fPtr = fopen(fileID, "r");
    if (fPtr == NULL){
        printf("File '%s' could not be opened.\n", fileID);
        return 100;
    } // if

    // Parse file and classify words by its inicial letter and print how many words are in each letter
    wordClassifier(fPtr);

    // Close file
    fclose(fPtr);
    return 0;
} // main