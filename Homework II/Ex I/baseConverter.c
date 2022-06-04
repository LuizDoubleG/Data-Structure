#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stacksADT.h"
#include "baseConverter.h" //Contains the function prototypes for the cylinder functions and struct definitions
#define MAX_LENGTH 10000
#define ERR_INVALID_NUMBER "The number must be positive. Please type another number.\n"
#define ERR_INVALID_BASE "The base must be positive. Please type another number.\n"

//Asks a decimal number from the user until it is valid
void getNumber(int* number){
    do{
    printf("Enter the decimal: ");
    scanf("%d", number);
    if (*number < 0){
        printf(ERR_INVALID_NUMBER);
    }// if
    }while(*number < 0); // do while
} // getNumber

//Asks a number base from the user until it is valid
void getBase(int* base){
    do{
    printf("Enter the base: ");
    scanf("%d", base);
    if (*base <= 0){
        printf(ERR_INVALID_BASE);
    }// if
    }while(*base <= 0); // do while
} // getBase

//Converts a decimal number to another number base
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
    // Allocate memory to and initialize variable to store converted number
    convertedNumber = (char*)malloc(sizeof(char)*MAX_LENGTH);
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

    // Return value
    while (!emptyStack(stack)){
        dataPtr = (char*)popStack(stack);
        temp[0] = *dataPtr;
        strcat(convertedNumber, temp);
    } // while
    free (dataPtr);
    destroyStack(stack);
    return convertedNumber;
} // convert
