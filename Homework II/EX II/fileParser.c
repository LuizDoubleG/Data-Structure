#include <stdio.h>
#include <stdlib.h>
#include "stacksADT.h"
#include "fileParser.h"

// Error Messages
#define ERR_OPENING_CB "Opening Curly Bracket '{' missing at line"
#define ERR_CLOSING_CB "Closing Curly Bracket '}' missing at line"
#define ERR_OPENING_SB "Opening Square Bracket ']' missing at line"
#define ERR_CLOSING_SB "Closing Square Bracket '[' missing at line"
#define ERR_OPENING_PAREN "Opening Parenthesis '(' missing at line"
#define ERR_CLOSING_PAREN "Closing Parenthesis ')' missing at line"

// Error Counter
int errorCount = 0;

// Function Prototypes

// Auxiliar function of parseFile: Check for missing opening parenthesis
void parentesesParse (char token, STACK* stack, char* dataPtr, int lineCount){

    if (token == '('){
        dataPtr = (char*) malloc (sizeof(char));
        *dataPtr = token;
        pushStack (stack, dataPtr);
    } // if
    else if (token == ')'){
        if (emptyStack(stack)){
            printf("%s %d\n", ERR_OPENING_PAREN, lineCount);
            errorCount++;
        } // if
        else if (*(char*)stackTop(stack) != '('){
            printf("%s %d\n", ERR_OPENING_PAREN, lineCount);
            errorCount++;
        } // else if
        else{
            popStack(stack);
        } // else
    } // else if
} // parentesesParse

// Auxiliar function of parseFile: Check for missing opening square brackets
void squareBracketsParse (char token, STACK* stack, char* dataPtr, int lineCount){

    if (token == '['){
        dataPtr = (char*) malloc (sizeof(char));
        *dataPtr = token;
        pushStack (stack, dataPtr);
    } // if
    else if (token == ']'){
        if (emptyStack(stack)){
            printf("%s %d\n", ERR_OPENING_SB, lineCount);
            errorCount++;
        } // if
        else if (*(char*)stackTop(stack) != '['){
            printf("%s %d\n", ERR_OPENING_SB, lineCount);
            errorCount++;
        } // else if
        else{
            popStack(stack);
        } // else
    } // else if
} // squareBracketsParse

// Auxiliar function of parseFile: Check for missing opening curly brackets
void curlyBracketsParse (char token, STACK* stack, char* dataPtr, int lineCount){

    if (token == '{'){
        dataPtr = (char*) malloc (sizeof(char));
        *dataPtr = token;
        pushStack (stack, dataPtr);
    } // if
    else if (token == '}'){
        if (emptyStack(stack)){
            printf("%s %d\n", ERR_OPENING_CB, lineCount);
            errorCount++;
        } // if
        else if (*(char*)stackTop(stack) != '{'){
            printf("%s %d\n", ERR_OPENING_CB, lineCount);
            errorCount++;
        } // else if
        else{
            popStack(stack);
        } // else
    } // else if
} // curlyBracketsParse

// Parses the file lines to checks the match of Square Bracket {}, Curly Brackets [] and Parentheses ().
void parseFile(FILE* fPtr){
//	Local Definitions
    STACK* stack;
    char token;
    char* dataPtr;
    int lineCount = 1;
    char aux;

    // Create Stack
    stack = createStack();

    // Parse file
    while ((token = fgetc (fPtr)) != EOF){

        if (token == '\n'){
            // Check for missing closing parenthesis at line
            if (emptyStack(stack) && errorCount == 0){
                printf("Parsing is OK at line %d.\n", lineCount);
            } // if 
            else {
                while (!emptyStack(stack)){
                    aux = *(char*)popStack(stack);
                    if (aux == '('){
                        printf("%s %d\n", ERR_CLOSING_PAREN, lineCount);
                    } // if
                    else if (aux == '['){
                        printf("%s %d\n", ERR_CLOSING_SB, lineCount);
                    } // else if
                    else if (aux == '{'){
                        printf("%s %d\n", ERR_CLOSING_CB, lineCount);
                    } // else if
                } // while
            } // else
            lineCount++;
            errorCount = 0;
        } // if

        if (token == '(' || token == ')'){
            parentesesParse (token, stack, dataPtr, lineCount);
        } // if

        else if (token == '[' || token == ']'){
            squareBracketsParse (token, stack, dataPtr, lineCount);
        } // else if

        else if (token == '{' || token == '}'){
           curlyBracketsParse (token, stack, dataPtr, lineCount); 
        } // else if
    } // while

    // Destroy the stack
    destroyStack(stack);

} // parseFile

