#include <stdio.h>
#include <time.h>

void randomValues(int* array, int size){
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

void assignValues(int* array, int size){
    int i;

    printf("Enter the elements: ");
    for (i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
}

void printArray(int *array, int size){
    int i;
    
    for (i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubblesort(int* array, int size, int* flag){
    int i, j, temp;
    for(i = 0; i < size - 1; i++){
        for(j = size - 1; j > i ; j--){
            if(array[j] < array[j - 1]){
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                *flag += 3;
                //flag = 0;
            }
        }
        // if(flag == 1){
        //     break;
        // }
        // flag = 1;
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

    bubblesort(array, size, &flag);

    printf("Sorted array: ");
    printArray(array, size);

    printf("\nOperations count: %d", flag);
}
