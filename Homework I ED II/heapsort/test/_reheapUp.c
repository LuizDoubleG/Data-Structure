#include "heapADT.h"

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