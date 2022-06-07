/*	Classifies text file words by its inicial letter, then print how many words are in each letter.
	   Written by: LuizDoubleG
	   Date: 06 06 2022
*/


#include <stdio.h>
#include "linkListADT.h"
#include "polynomialListADT.h"

int main(void){
// Local definitions
    LIST *polynomial1 = createList(compare);
    LIST *polynomial2 = createList(compare);
    LIST *polynomialFinal = createList(compare);
    
// Statements
    addNode(polynomial1, create_monomial(7, 4));
    addNode(polynomial1, create_monomial(6, 3));
    addNode(polynomial1, create_monomial(7, 0));
    addNode(polynomial1, create_monomial(2, 3));
    addNode(polynomial1, create_monomial(-3, 2));
    addNode(polynomial2, create_monomial(3, 1));
    addNode(polynomial2, create_monomial(1, 1));
    addNode(polynomial2, create_monomial(2, 0));
    addNode(polynomial2, create_monomial(-3, 2));
    addNode(polynomial2, create_monomial(4, 2));

   
    printf("Number of Polynomial 1 elements: %d\n", listCount(polynomial1));
    printList(polynomial1);
    printf("Number of Polynomial 2 elements: %d\n", listCount(polynomial2));
    printList(polynomial2);

    sumPolynomials(polynomial1, polynomial2, polynomialFinal);
    printf("Number of Polynomial Final elements: %d\n", listCount(polynomialFinal));
    printList(polynomialFinal);

    return 0;
} // main