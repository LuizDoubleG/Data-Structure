#include <stdio.h>
#include <stdlib.h>
#include "linkListADT.h"

//	List ADT Structure Definitions

/*	=============== createList ==============

/*	================== addNode =================

/*	=================== _insert ==================

/*	================= removeNode ================
/*	================= _delete ================

/*	================== searchList =================

/*	================== _search =================
	Searches list and passes back address of node
	containing target and its logical predecessor.
	   Pre    pList pointer to initialized list
	          pPre  pointer variable to predecessor
	          pLoc  pointer variable to receive node
	          pArgu pointer to key being sought
	   Post   pLoc points to first equal/greater key
	     -or- null if target > key of last node
	          pPre points to largest node < key
	     -or- null if target < key of first node
	   Return boolean true found; false not found

*/
static bool _search (LIST*  pList, NODE** pPre,
              NODE** pLoc,  void*  pArgu)
{
//	Macro Definition
#define COMPARE \
	( ((* pList->compare) (pArgu, (*pLoc)->dataPtr)) )

#define COMPARE_LAST \
	((* pList->compare) (pArgu, pList->rear->dataPtr))

//	Local Definitions
	int result;

//	Statements
	*pPre  = NULL;
	*pLoc  = pList->head;
	if (pList->count == 0)
	    return false;

	// Test for argument > last node in list
	if ( COMPARE_LAST > 0)
	   {
	    *pPre = pList->rear;
	    *pLoc = NULL;
	    return false;
	   } // if

	while ( (result = COMPARE) > 0 )
	   {
	    // Have not found search argument location
	    *pPre = *pLoc;
	    *pLoc = (*pLoc)->link;
	   } // while

	if (result == 0)
	   // argument found--success
	   return true;
	else
	   return false;
}	// _search

/*	================== retrieveNode ================
	This algorithm retrieves data in the list without
	changing the list contents.
	   Pre    pList pointer to initialized list.
	          pArgu pointer to key to be retrieved
	   Post   Data (pointer) passed back to caller
	   Return boolean true success; false underflow
*/
bool retrieveNode (LIST*  pList,
                          void*  pArgu,
                          void** dataOutPtr)
{
//	Local Definitions
	bool  found;

	NODE* pPre;
	NODE* pLoc;

//	Statements
	found = _search (pList, &pPre, &pLoc, pArgu);
	if (found)
	   {
	    *dataOutPtr = pLoc->dataPtr;
	    return true;
	   } // if

	*dataOutPtr = NULL;
	return false;
}	// retrieveNode

/*	================= emptyList ================

/*	================== fullList =================

/*	================== listCount ==================

/*	================== traverse =================

/*	================== destroyList =================

