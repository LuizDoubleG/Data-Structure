#ifndef POLYNOMIALLISTADT_H_INCLUDED
#define POLYNOMIALLISTADT_H_INCLUDED

//	List ADT Type Definitions
typedef struct monomial Monomial;
//	Prototype Declarations
Monomial* create_monomial(int coefficient, int exponent);
int compare(void* m1, void* m2, int flag);
void remove0CoefficientsMonomials(LIST* polynomial);
void printList(LIST *polynomial);
void sumPolynomials(LIST *polynomial1, LIST *polynomial2, LIST *result);
void readPolynomialFile(FILE* fPtr, LIST *polynomial);
void readPolynomialString(char* polynomialString, LIST *polynomial);
//	End of List ADT Definitions

#endif // POLYNOMIALLISTADT_H_INCLUDED