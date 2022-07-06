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
    if (coefficient == 0)
    {
        return NULL;
    } // if
    Monomial *monomial = (Monomial *)malloc(sizeof(Monomial));
    monomial->coefficient = coefficient;
    monomial->exponent = exponent;
    return monomial;
} // create_monomial

int compare(void* m1, void* m2, int flag)
{
// Statements
    
    if (((Monomial*)m1)->exponent < ((Monomial*)m2)->exponent){
        return 1;
    } // if
    else if (((Monomial*)m1)->exponent == ((Monomial*)m2)->exponent && flag == 0){
        ((Monomial*)m2)->coefficient +=((Monomial*)m1)->coefficient;
            return 0;
    } // else if
    else if (((Monomial*)m1)->coefficient == ((Monomial*)m2)->coefficient == 0){
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
    while (traverse(polynomial, i, (void **)&monomial)){
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

        if (monomial->coefficient != 0)
        {
            if (monomial->exponent == 0)
            {
                printf("%d", monomial->coefficient);
            } // if
            else{
            printf("%ix^%i", monomial->coefficient, monomial->exponent);
            } // else
        } // if
        else if (listCount(polynomial) == 1)
        {
            printf("0");
        } // else if
        i++;
    } // while
    printf("\n");
} // printList

void sumPolynomials(LIST *polynomial1, LIST *polynomial2, LIST *result)
{
// Local Declarations
    int i = 0;
    Monomial* monomial1;
    Monomial* monomial2;
// Statements
   while (traverse(polynomial1, i, (void **)&monomial1))
   {
       addNode(result, monomial1);
       i++;
   } // while

    i = 0;

    while (traverse(polynomial2, i, (void **)&monomial2))
    {
        addNode(result, monomial2);
        i++;
    } // while

} // sumPolynomials

void readPolynomialFile(FILE* fPtr, LIST *polynomial)
{
// Local Declarations
    int coefficient;
    int exponent;
    Monomial *monomial;
    int negativeFlag = 0;
    int token;
// Statements
    while ((token = fgetc(fPtr)) != EOF){
        while (!(token >= '0' && token <= '9' && token != '\n')){
            if (token == '-'){
                negativeFlag = 1;
            } // if
            token = fgetc(fPtr);
        } // while

        coefficient = 0;
        while (token >= '0' && token <= '9'){
            coefficient = coefficient * 10 + token - '0';
            token = fgetc(fPtr);
        } // while
         if (negativeFlag == 1){
            coefficient = -coefficient;
        } // if

        negativeFlag = 0;
        while (!(token >= '0' && token <= '9' && token != '\n')){
            if (token == '-'){
                negativeFlag = 1;
            } // if
            token = fgetc(fPtr);
        } // while

        exponent = 0;
        while (token >= '0' && token <= '9'){
            exponent = exponent * 10 + token - '0';
            token = fgetc(fPtr);
        } // while
         if (negativeFlag == 1){
            coefficient = -coefficient;
        } // if

        negativeFlag = 0;

        monomial = create_monomial(coefficient, exponent);
        if (monomial != NULL){
            addNode(polynomial, monomial);
        } // if
        if (token == '\n'){
            break;
        } // if
    } // while
} // readPolynomialFile

void readPolynomialString(char* polynomialString, LIST *polynomial)
{
// Local Declarations
    int coefficient;
    int exponent;
    int i = 0;
    int negativeFlag = 0;
    Monomial *monomial;
    
// Statements
   while (polynomialString[i] != '\0'){
        while (!(polynomialString[i] >= '0' && polynomialString[i] <= '9' && polynomialString[i] != '\0')){
            if (polynomialString[i] == '-'){
                negativeFlag = 1;
            } // if
            i++;
        } // while

        coefficient = 0;
        while (polynomialString[i] >= '0' && polynomialString[i] <= '9' ){
            coefficient = coefficient * 10 + polynomialString[i] - '0';
            i++;
        } // while

        if (negativeFlag == 1){
            coefficient = -coefficient;
        } // if

        negativeFlag = 0;
        while (!(polynomialString[i] >= '0' && polynomialString[i] <= '9' && polynomialString[i] != '\0')){
            if (polynomialString[i] == '-'){
                negativeFlag = 1;
            } // if
            i++;
        } // while

        exponent = 0;
        while (polynomialString[i] >= '0' && polynomialString[i] <= '9'){
            exponent = exponent * 10 + polynomialString[i] - '0';
            i++;
        } // while

        if (negativeFlag == 1){
            exponent = -exponent;
        } // if

        monomial = create_monomial(coefficient, exponent);
        if (monomial != NULL){
            addNode(polynomial, monomial);
        } // if

        negativeFlag = 0;

        i++;
    } // while
} // readPolynomialString