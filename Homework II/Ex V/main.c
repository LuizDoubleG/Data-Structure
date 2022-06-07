/*	Reads files or strings of polynomials and sum them into one polynomial using lists ADT, then prints them.
	   Written by: LuizDoubleG
	   Date: 06 06 2022
*/

//	Macro Definition
#define MAX_FILE_NAME 25
#define MAX_POLYNOMIALENTER_NAME 50

#include <stdio.h>
#include "linkListADT.h"
#include "polynomialListADT.h"


int main(void){
// Local definitions
    LIST *polynomial1 = createList(compare);
    LIST *polynomial2 = createList(compare);
    LIST *polynomialFinal = createList(compare);
    FILE* fPtr;
    int choice;
    char fileID[MAX_FILE_NAME];
    char polynomialEnter[MAX_POLYNOMIALENTER_NAME] = {'\0'};
    
// Statements
    printf("Want to read a file (0) or type the polynomials (1)? ");
    scanf("%d", &choice);
    if (choice == 0){
        // Ask user for file name
        printf ("Enter the file name for file to have its words classified: ");
        scanf("%s", fileID);

        // Open file
        fPtr = fopen(fileID, "r");
        if (fPtr == NULL){
            printf("File '%s' could not be opened.\n", fileID);
            return 100;
        } // if

        // Read file
        readPolynomialFile(fPtr, polynomial1);
        readPolynomialFile(fPtr, polynomial2);
        fclose(fPtr);
    } // if
    else if (choice == 1){
        // Ask user for polynomials
        printf ("Enter the first polynomial: ");
        scanf(" %[^\n]", &polynomialEnter);
        readPolynomialString(polynomialEnter, polynomial1);
        printf ("Enter the second polynomial: ");
        scanf(" %[^\n]", &polynomialEnter);
        readPolynomialString(polynomialEnter, polynomial2);
    } // else if
    else{
        printf("Invalid choice.\n");
        return 100;
    } // else
   
    printf("Number of Polynomial 1 elements: %d\n", listCount(polynomial1));
    printList(polynomial1);
    printf("Number of Polynomial 2 elements: %d\n", listCount(polynomial2));
    printList(polynomial2);

    sumPolynomials(polynomial1, polynomial2, polynomialFinal);
    printf("Number of Polynomial Final elements: %d\n", listCount(polynomialFinal));
    printList(polynomialFinal);

    destroyList(polynomial1);
    destroyList(polynomial2);
    destroyList(polynomialFinal);
    return 0;
} // main