#include "heapADT.h"

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
            heap->heapArra[largeLoc]) < 0)
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