#ifndef QUEUESADT_H_INCLUDED
#define QUEUESADT_H_INCLUDED

#include <stdbool.h>

typedef struct node QUEUE_NODE;
typedef struct queue QUEUE;

//	Prototype Declarations
QUEUE* createQueue (void);
bool enqueue (QUEUE* queue, void* itemPtr);
void catQueueI (QUEUE* queue, QUEUE* queue2);
bool catQueueII (QUEUE* queue, QUEUE* queue2);
bool dequeue (QUEUE* queue, void** itemPtr);
bool queueFront (QUEUE* queue, void** itemPtr);
bool queueRear (QUEUE* queue, void** itemPtr);
bool emptyQueue (QUEUE* queue);
bool fullQueue (QUEUE* queue);
int queueCount(QUEUE* queue);
void printQueue (QUEUE* queue);
QUEUE* destroyQueue (QUEUE* queue);
//	End of Queue ADT Definitions

#endif // QUEUESADT_H_INCLUDED
