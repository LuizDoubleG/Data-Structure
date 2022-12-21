/* Data Structures for heap ADT
        Created by: LuizDoubleG
        Date: 30/09/2022 
*/
#include <stdbool.h>

typedef struct
{
    void** heapArray;
    int last;
    int size;
    int (*compare) (void* argu1, void* argu2);
    int maxSize;
} HEAP;

// Prototype Definitions 
HEAP* heapCreate (int maxSize,
                  int(*compare) (void* arg1, void* arg2));
bool heapInsert (HEAP* heap, void* dataPtr);
bool heapDelete (HEAP* heap, void** dataOutPtr);
bool heapPrint (HEAP* heap);
int heapCount (HEAP* heap);
bool heapFull (HEAP* heap);
bool heapEmpty (HEAP* heap);
void heapDestroy (HEAP* heap);
HEAP* heapSort (const int *const vector,
               int vectorSize,
               int(*compare) (void* arg1, void* arg2));

static void _reheapUp (HEAP* heap, int childLoc);
static void _reheapDown (HEAP* heap, int root);
