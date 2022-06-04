/*	This converts a decimal number to hexadecimal usind the sucessive division method and stacks.
	    Written by: LuizDoubleG
	    Date: 30/05/2022
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stacksADT.h"

//Convertion function
const char* convert(int* number, int* base);

int main(void){
//	Local Definitions
    //STACK* stack;
    int decNumber;
    int base;
    //char* convertedNumber;

//	Statements
    //convertedNumber = (char*)malloc(sizeof(char)*100);

    // Get decimal number
    do{
    printf("Enter the decimal: ");
    scanf("%d", &decNumber);
    if (decNumber < 0){
        printf("The number must be positive. Please type another number.\n");
    }// if
    }while(decNumber < 0); // do while

    // Get base of conversion
    do{
    printf("Enter the base: ");
    scanf("%d",&base);
    if (base < 0){
        printf("The base must be positive. Please type another number.\n");
    }// if
    }while(decNumber < 0); // do while

    // Convert number and Print converted number
    printf("The number in base %d is: ", base);
    printf("%s\n", convert(&decNumber, &base));

    return 0;
} // main

//Convertion function
const char* convert(int* number, int* base){
//	Local Definitions
    STACK* stack;
    int remainder;
    int quotient;
    char* dataPtr; 
    char temp[2] = {0};
    char *convertedNumber;

//	Statements
	// Create Stack
    stack = createStack();
    // Initialize variable to store converted number
    convertedNumber = (char*)malloc(sizeof(char)*100);
    *convertedNumber = '\0';

    // Division method
    quotient = *number; 
    while (quotient >= *base){
        dataPtr  = (char*) malloc (sizeof(char));
        remainder = quotient % *base;
        if (remainder < 10){
            *dataPtr = remainder + '0';
        } // if
        else {
            *dataPtr = remainder + 'A' - 10;
        } // else
        pushStack (stack, dataPtr);
        quotient = quotient / *base;
    } // while 

    dataPtr  = (char*) malloc (sizeof(char));
    if (quotient < 10){
        *dataPtr = quotient + '0';
    } // if
    else {
        *dataPtr = quotient + 'A' - 10;
    } // else
    pushStack (stack, dataPtr);

    // return value
    while (!emptyStack(stack)){
        dataPtr = (char*)popStack(stack);
        temp[0] = *dataPtr;
        //strcat(convertedNumber, temp);
        strcat(convertedNumber, temp);
    } // while
    free (dataPtr);
    destroyStack(stack);
    return convertedNumber;
}