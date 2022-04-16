#include <stdio.h>
#include <time.h>

void assignValues(int* array, int size){
    int i;

    printf("Enter the elements: ");
    for (i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
}

void randomValues(int* array, int size){
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

void printArray(int *array, int size){
    int i;
    
    for (i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int* array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void insertionSort(int* array, int size, int* flag){
    int i, j, temp;
    for(i = 1; i < size; i++){
        temp = array[i];
        *flag = *flag + 1;
        j = i - 1;
        while(j >= 0 && array[j] > temp){
            *flag = *flag + 1;
            array[j + 1] = array[j];
            *flag = *flag + 1;
            j--;
        }
        array[j + 1] = temp;
        *flag = *flag + 1;
    }
}

int main (void){
    int size, flag = 0, option;
    time_t tStrt, tEnd; // Variables to measure the time

    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int array[size];

    printf("Want to enter the elements manually? (1/0) ");
    scanf("%d", &option);

    if (option == 1){
        assignValues(array, size);
    }
    else{
        srand((unsigned)time(NULL));
        randomValues(array, size);
    }
    printf("Input array: ");
    printArray(array, size);

    tStrt = clock(); // Start the clock
    insertionSort(array, size, &flag);
    tEnd = clock(); // Stop the clock

    printf("Sorted array: ");
    printArray(array, size);

    printf("\nOperations count: %d\n", flag);
    
    printf("\nTime in seconds: %f sec\n\n", (double)(tEnd - tStrt) / CLOCKS_PER_SEC );

    return 0;
}

