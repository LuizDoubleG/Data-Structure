#include <stdio.h>
#include <time.h>
//assert -> 92

unsigned long long flag = 0; // flag to check number of operations

unsigned long long iterativeFibonacci(int seriesSize) { //Delivers correct results up to exact position 93
    int i;
    unsigned long long current_term = 1, previous_term = 1;
    
	flag += 3; // This if function equals to 3 operations
    if (seriesSize == 0 || seriesSize == 1) { // base case
        return seriesSize;
    }
    for (i = 2; i < seriesSize; i++){  // i = 2 because we already have 0 and 1
        current_term += previous_term; 
        flag++;
        previous_term = current_term - previous_term;
        flag++; 
    }
    return current_term;
}

int main (void) {
    int seriesSize; // Number of fibonacci numbers to print
    time_t tStrt, tEnd; // Variables to measure the time
    

    printf("Enter the number of fibonacci numbers to print: ");
    scanf("%d", &seriesSize);
    
    tStrt = clock(); // Start the clock
    flag++; //First operation of the function (assignment)
    printf("\nThe %dth number of Fibonacci is: %llu", seriesSize, iterativeFibonacci(seriesSize));
    tEnd = clock(); // Stop the clock


    printf ("\n\nNumber of operations: %llu\n", flag);

    printf("\nTempo em segundos: %f sec\n\n", (double)(tEnd - tStrt) / CLOCKS_PER_SEC );

    return 0;
}
