/*	Fill 2 queues with random int numbers from 0 to 100 and concactenate them into one queue, then print it.
	   Written by: LuizDoubleG
	   Date: 05 06 2022
*/

#include <stdio.h> // Print functions
#include <stdlib.h> // malloc, rand() and srand()
#include "QueuesADT.h" // ADT for queues 

// Prototypes 
void fillQueue (QUEUE* queue, int n);

int main (void)
{
// Local Definitions
    QUEUE *q1, *q2, *aux; // aux queue to save state of q1 before concatenating and test catQueueII
    int i;

//	Statements
    printf("Welcome to a demonstration of queues.\n");
    
    q1 = createQueue();
    q2 = createQueue();
    aux = createQueue();

    srand(79);

    printf("Please enter the number of items to be added to the queue: ");
    scanf("%d", &i);
    printf("Queue 1 : ");
    fillQueue(q1, i);

    printf("Please enter the number of items to be added to the queue: ");
    scanf("%d", &i);
    printf("Queue 2: ");
    fillQueue(q2, i);
    
    catQueueI(aux, q1);
    catQueueI(q1, q2);
    printf("Queue 1 with Queue 2 (catQueueI): ");
    printQueue(q1);

    printf("State of Queue 2: ");
    printQueue(q2);

    catQueueII(aux, q2);
    printf("Queue 1 with Queue 2 (catQueueII): ");
    printQueue(aux);

    printf("State of Queue 2: ");
    printQueue(q2);

    destroyQueue(q1);
    destroyQueue(q2);
    return 0;
} // main

void fillQueue (QUEUE* queue, int n)
{
//	Local Definitions
    int* dataPtr;
    int i;

// Statements
    for (i = 1; i <= n; i++)
    {
        if (!(dataPtr = (int*) malloc (sizeof (int))))
        {
            printf("Overflow in fillQueues\a\n");
            exit (100);
        } // if
        *dataPtr = rand() % 100;
        printf("%3d", *dataPtr);
        enqueue(queue, dataPtr);
    } // for
    printf("\n");
} // fillQueue  