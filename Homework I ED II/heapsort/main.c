#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "heapADT.h"

int compareInt(void* num1, void* num2)
{
// Local Definitions
    int num1Int = *(int*)num1;
    int num2Int = *(int*)num2;

// Statements
    if (num1Int < num2Int)
        return -1;
    else if (num1Int > num2Int)
        return 1;
} // compareInt

int main (){
// Local Definitions 
    int size, counter, hold;
    HEAP* heapSorted;

// Statements
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    int vector[size];
    int copyVector[size];
        
    srand(time(NULL));
    for (counter = 0; counter < size; counter++)
    {
        hold = rand()%(size*2);
        vector[counter] = hold;
        copyVector[counter] = hold;
    } // for
    /*
    printf("Vetor:");
    for (counter = 0; counter < size; counter++)
    {
        printf(" %d ", vector[counter]);
    } // for
    printf("\n");
    printf("Vetor Copia:");
    for (counter = 0; counter < size; counter++)
    {
        printf(" %d ", copyVector[counter]);
    } // for
    printf("\n");
    */
    heapSorted = heapSort (vector, size, compareInt);
    heapPrint (heapSorted);

    return 0;
} // main
