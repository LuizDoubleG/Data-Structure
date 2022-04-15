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

void selectionSort(int* array, int size, int* flag){
    int i, j, min, temp;
    
    for(i = 0; i < size - 1; i++){
        min = i;
        for(j = i + 1; j < size; j++){
            *flag = *flag + 1;
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            swap (array, i, min);
            *flag = *flag + 3;
        }
    }
}

int main (void){
    int size, flag = 0, option;

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

    selectionSort(array, size, &flag);

    printf("Sorted array: ");
    printArray(array, size);

    printf("\nOperations count: %d\n", flag);
}

