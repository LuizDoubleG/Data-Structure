#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include "heapADT.h"

HEAP* heapCreate (int maxSize, 
                  int (*compare) (void* argu1, void* argu2))
{ 
// Local Definitions 
    HEAP* heap;

// Statements
    heap = (HEAP*)malloc(sizeof (HEAP));
    if (!heap)
        return NULL;
    heap -> size = 0;
    heap -> last = -1;
    heap -> compare = compare;

    /* Force heap size to power of 2 -1 (2^log2(maxsize) = maxsize 
                                        (sendo que arredondado por ceil, 
                                        força que maxsize sempre seja uma 
                                        potencia de 2 (-1 é pra regularizar 
                                        o ceil que arredonda pra cima)))
    */
    heap -> maxSize = 
                     (int) pow (2, ceil(log2(maxSize))) - 1;
    heap -> heapArray = (void*)
                        calloc(heap -> maxSize, sizeof(void*)); // Reserves maxSize void size spaces 
    return heap;
} // heapCreate

bool heapInsert (HEAP* heap, void* dataPtr)
{
// Statements 
    if (heap->size == 0)
    {
        heap->size = 1;
        heap->last = 0;
        heap->heapArray[heap->last] = dataPtr;
        return true;
    } // if
    if (heap->last == heap->maxSize - 1)
        return false;
    ++(heap->last);
    ++(heap->size);
    heap->heapArray[heap->last] = dataPtr;
    _reheapUp (heap, heap->last);
    return true;
} // heapInsert

bool heapDelete (HEAP* heap, void** dataOutPtr)
{
// Statements
    if (heap->size == 0)
        // heap empty
        return false;
    *dataOutPtr = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[heap->last];
    (heap->last)--;
    (heap->size)--;
    _reheapDown (heap, 0);
    return true;
} // heapDelete

bool heapPrint (HEAP* heap)
{
// Local Definitions
    int count;
    
// Statements
    if (heap->size == 0)
        // heap empty
        return false;
    printf ("Vetor Ordenado: ");
    for (count = 0; count < heap->size; count++)
    {
        printf (" %d ", *(int *)(heap->heapArray[count]));
    } // for

    return true;
} // heapDelete

HEAP* heapSort (const int *const vector, int vectorSize, int(*compare) (void* arg1, void* arg2))
{
// Local Definitions 
    int sorted;
    // void** heapArray;
    void* hold;
    int counter;
    int* numbHold;
    HEAP* heap;
 
    /*
    printf("Vector dentro:");
    for (counter = 0; counter < vectorSize; counter++)
    {
        printf(" %d ", vector[counter]);
    } // for
    printf("\n");
    */

// Statements 
    // Create Heap
    heap = heapCreate (vectorSize, compare);
    for (counter = 0; counter < vectorSize; counter++){
        numbHold = (int*)malloc(sizeof(int));
        *numbHold = vector[counter];
        heapInsert(heap, numbHold);
    } // for

    // Heap created. Now sort it.
    sorted = heap->last; // Heap size (should be == vectorSize)
    while (sorted > 0) // Until heap size is 1
    {
        hold = heap->heapArray[0];
        heap->heapArray[0] = heap->heapArray[sorted];
        heap->heapArray[sorted] = hold;
        sorted --;
        heap->last = sorted;
        _reheapDown (heap, 0);
    } // while
    heap->last = vectorSize-1;
    return heap;
} // heapSort

void _reheapUp (HEAP* heap, int childLoc)
{
// Local Definitions 
    int parent;
    void** heapArray;
    void* hold;
// Statements 
    // if not at root of heap == index 0
    if (childLoc)
    {
        heapArray = heap->heapArray;
        parent = (childLoc - 1) / 2;
        if (heap->compare(heapArray[childLoc],
                          heapArray[parent]) > 0)
            // child is grater than parent == swap
        {
            hold = heapArray[parent];
            heapArray[parent] = heapArray[childLoc];
            heapArray[childLoc] = hold;
            _reheapUp (heap, parent);
        } // if
    } // if
    return;
} // _reheapUp

void _reheapDown (HEAP* heap, int root)
{
// Local Definitions
    void* hold;
    void* leftData;
    void* rightData;
    int largeLoc;
    int last;

// Statements 
    last = heap->last;
    if ((root * 2 + 1) <= last) // left subtree
        // There is at leat one child
    {
        leftData = heap->heapArray[root * 2 + 1];
        if ((root * 2 + 2) <= last) // right subtree
            rightData = heap->heapArray[root * 2 + 2];
        else 
            rightData = NULL;
        // Determine which child is larger 
        if ((!rightData)
            || heap->compare (leftData, rightData) > 0)
        { 
            largeLoc = root * 2 + 1;
        } // if no right key or leftKey grater 
        else 
        {
            largeLoc = root * 2 + 2;
        } // else
        // Test if root > large subtree
        if (heap->compare(heap->heapArray[root],
            heap->heapArray[largeLoc]) < 0)
            {
                hold = heap->heapArray[root];
                heap->heapArray[root] =
                    heap->heapArray[largeLoc];
                heap->heapArray[largeLoc] = hold;
                _reheapDown (heap, largeLoc);
            } // if root minor
    } // if root
    return;
} // reheapDown


