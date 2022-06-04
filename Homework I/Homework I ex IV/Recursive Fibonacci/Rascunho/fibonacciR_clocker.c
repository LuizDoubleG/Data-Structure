#include <stdio.h>
#include <time.h>

long long flag = 0; // flag to check number of operations

long long recursiveFibonacci(int seriesSize) {
   
    flag+= 3; // This if function equals to 3 operations
    if (seriesSize == 0 || seriesSize == 1) {
        return seriesSize;
    }
    flag+=2; // This return function equals to 2 operations (assignment)
    return (recursiveFibonacci(seriesSize - 1) + recursiveFibonacci(seriesSize - 2));
}

int main (void) {
    int seriesSize; // Number of fibonacci numbers to print
    //int counter; // Counter for the loop
    time_t tStrt, tEnd; // Variables to measure the time
    

    printf("Enter the number of fibonacci numbers to print: ");
    scanf("%d", &seriesSize);
    
    ///*
    tStrt = clock(); // Start the clock
    flag++; //First operation of the function (assignment)
    printf("\nThe %dth number of Fibonacci is: %lld", seriesSize, recursiveFibonacci(seriesSize));
    tEnd = clock(); // Stop the clock
    //*/
    //ou
    /*
    tStrt = time(NULL);
     printf("\nThe %dth number of Fibonacci is: %lld", seriesSize, recursiveFibonacci(seriesSize));
    tEnd = time(NULL);
    */  

    printf ("\n\nNumber of operations: %lld\n", flag);

    printf("\nTempo em segundos: %f sec\n\n", (double)(tEnd - tStrt) / CLOCKS_PER_SEC );
    //printf("\nTempo em segundos: %f\n", difftime(tEnd, tStrt)); 

    return 0;
}
