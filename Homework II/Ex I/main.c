/*	This program converts a decimal number to hexadecimal usind the sucessive division method and stacks.
	    Written by: LuizDoubleG
	    Date: 30/05/2022
*/

#include <stdio.h>
#include "baseConverter.h"

int main(void){
//	Local Definitions
    int decNumber;
    int base;

//	Statements
    // Get decimal number
    getNumber(&decNumber);

    // Get base of conversion
    getBase(&base);
    
    // Convert number and Print converted number
    printf("The number in base %d is: ", base);
    printf("%s\n", convert(&decNumber, &base));

    return 0;
} // main

