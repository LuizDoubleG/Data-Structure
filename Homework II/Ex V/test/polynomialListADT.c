#include <stdio.h>
#include <stdlib.h>
#include "linkListADT.h"
#include "polynomialListADT.h"

//	List ADT Structure Definitions
struct monomial {
  int coefficient;
  int exponent;
};

Monomial* create_monomial(int coefficient, int exponent)
{
// Statements
    if (coefficient == 0 || exponent == 0)
    {
        return NULL;
    } // if
    Monomial *monomial = (Monomial *)malloc(sizeof(Monomial));
    monomial->coefficient = coefficient;
    monomial->exponent = exponent;
    return monomial;
} // create_monomial

int compare(void* m1, void* m2)
{
// Statements
    if (((Monomial*)m1)->exponent < ((Monomial*)m2)->exponent){
        return 1;
    } // if
    else if (((Monomial*)m1)->exponent == ((Monomial*)m2)->exponent){
        ((Monomial*)m2)->coefficient += ((Monomial*)m1)->coefficient;
            return 0;
    } // else if
    else {
        return -1;
    } // else
} // compare

void remove0CoefficientsMonomials(LIST* polynomial)
{
// Local Definitions
    int i = 0;
    Monomial *monomial;
// Statements
    while (traverse(polynomial, i, (void *)&monomial)){
        if (monomial->coefficient == 0){
            removeNode(polynomial, monomial, NULL);
        } // if
        i++;
    } // while
} // remove0CoefficientsMonomials

void printList(LIST *polynomial)
{
// Local Declarations
    int i = 0;
    Monomial* monomial;

// Statements
    while (traverse(polynomial, i, (void *)&monomial))
    {
        if (i < listCount(polynomial) && i != 0)
        {
            if (monomial->coefficient >= 0)
            {
                 printf(" + ");
            } // if
            else
            {
                 printf(" ");
            } // else
        } // if
        printf("%ix^%i", monomial->coefficient, monomial->exponent);
        i++;
    } // while
    printf("\n");
} // printList

LIST* sumPolynomials(LIST *polynomial1, LIST *polynomial2, LIST *result)
{
// Local Declarations
    int i = 0;
    Monomial* monomial1;
    Monomial* monomial2;

// Statements
   while (traverse(polynomial1, i, (void *)&monomial1))
   {
       addNode(result, monomial1);
   } // while

    i = 0;

    while (traverse(polynomial2, i, (void *)&monomial2))
    {
        addNode(result, monomial2);
    } // while

} // sumPolynomials
