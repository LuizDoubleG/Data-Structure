#include "heapADT.h"

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
// Statements
    if (heap->size == 0)
        // heap empty
        return false;
    printf ("vetor: ");
    printf (" %d ", heap->heapArray[0]);
 
    return true;
} // heapDelete