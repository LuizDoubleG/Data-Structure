#include <stdio.h>

int flag = 0; // flag to check number of operations

long recursiveFibonacci(int seriesSize) {
   
    if (seriesSize == 0 || seriesSize == 1) {
        //printf ("entrou aqui");
        flag++;
        return seriesSize;
    }
    flag++;
    return (recursiveFibonacci(seriesSize - 1) + recursiveFibonacci(seriesSize - 2));
}

int main (void) {
    int seriesSize; // number of fibonacci numbers to print
    int counter; // counter for the loop
    
    //long aux; 

    printf("Enter the number of fibonacci numbers to print: ");
    scanf("%d", &seriesSize);
    //printf("The first %d fibonacci numbers are: \n", seriesSize);
    for (counter = 0; counter < seriesSize; counter++) {
        //aux = recursiveFibonacci(counter);
        // if (counter % seriesSize == 0) { // (aux % seriesSize) works too
        //     printf("%5ld,", aux);
        // }
        // else {
        //     printf("%5ld\n", aux); // print the last number without a comma
        // }
        printf("%8ld", recursiveFibonacci(counter));
    } 
    printf ("\nNumber of operations: %d\n", flag);
    return 0;
}