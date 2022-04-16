#include <stdio.h>
#include <time.h>

long long flag = 0; // flag to check number of operations

long long recursiveFibonacci(int seriesSize) {
   
    if (seriesSize == 0 || seriesSize == 1) {
        flag++;
        return seriesSize;
    }
    flag++;
    return (recursiveFibonacci(seriesSize - 1) + recursiveFibonacci(seriesSize - 2));
}

int main (void) {
    int seriesSize; // number of fibonacci numbers to print
    int counter; // counter for the loop
    time_t tStrt, tEnd; // variables to measure the time
    

    printf("Enter the number of fibonacci numbers to print: ");
    scanf("%d", &seriesSize);

    tStrt = clock(); // start the clock
    for (counter = 0; counter < seriesSize; counter++) {
        printf("%14lld", recursiveFibonacci(counter));
    } 
    tEnd = clock(); // stop the clock

    printf ("\n\nNumber of operations: %lld\n", flag);

    printf("\nTempo em segundos: %f sec\n\n", (double)(tEnd - tStrt) / CLOCKS_PER_SEC );

    //ou
    /*
    tStr = time(NULL);
    ... function
    tEnd = time(NULL);
    printf("\nTempo em segundos: %f\n", difftime(tEnd, tStr) ); 
    */

    return 0;
}