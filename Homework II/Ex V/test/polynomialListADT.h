#ifndef POLYNOMIALLISTADT_H_INCLUDED
#define POLYNOMIALLISTADT_H_INCLUDED

//	List ADT Type Definitions
typedef struct monomial Monomial;
//	Prototype Declarations
Monomial* create_monomial(int coefficient, int exponent);
int compare(void* m1, void* m2);
void remove0CoefficientsMonomials(LIST* polynomial);
void printList(LIST *polynomial);
LIST* sumPolynomials(LIST *polynomial1, LIST *polynomial2, LIST *result);
//	End of List ADT Definitions

#endif // POLYNOMIALLISTADT_H_INCLUDED