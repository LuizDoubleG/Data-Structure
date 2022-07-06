#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treeADT.h"

int compareInt(void* num1, void* num2)
{
// Local Definitions
    int num1Int = *(int*)num1;
    int num2Int = *(int*)num2;

// Statements
    if (num1Int < num2Int)
        return -1;
    else if (num1Int == num2Int)
        return 0;
    else
        return 1;
} // compareInt

void printInt(void* dataPtr)
{
// Statements
    printf("%d\n", *(int*)dataPtr);
} // printInt

int main(){
// Local Definitions
    BST_TREE* tree;
    int *dataPtr;
    NODE *rootPtr;
    int nodeQtt, counter, choice;

// Statements
    tree = BST_Create(compareInt);

    printf("Enter the number of nodes: ");
    scanf("%d", &nodeQtt);

    printf("\nDo you want to fill the tree with random values (1) or enter your own values (2)? ");
    scanf("%d", &choice);
    if (choice == 1){
        srand(time(NULL));
        for (counter = 0; counter < nodeQtt; counter++)
        {
        dataPtr = (int*)malloc(sizeof(int));
        *dataPtr = rand() % 100;
        BST_Insert(tree, dataPtr);
        } // for
    }
    else 
    {
        for (counter = 0; counter < nodeQtt; counter++)
        {
        dataPtr = (int*)malloc(sizeof(int));
        scanf("%d", dataPtr);
        BST_Insert(tree, dataPtr);
        } // for
    }
    
    do
    {
        system("pause");
        system("cls");
        printf("\nContetent of the tree: \n");
        BST_Traverse(tree, printInt);

        printf("\nDo you want to know the balance factor of the role tree (1) or of a subtree (2) or exit(0)? ");
        // insert reinsert tree option (switch..case)
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\nExiting...\n");
            exit(1);
            break;
        case 1:
            if (BST_Balance(tree, NULL))
            {
                printf("\nThe tree is balanced.\n");
            } // if
            else
            {
                printf("\nThe tree is not balanced.\n");
            } // else
            break;
        default:
            printf("\nEnter the content of the root of the subtree: ");
            scanf("%d", dataPtr);
            if (!(rootPtr = BST_Retrieve (tree, dataPtr))){
                printf("\nThe root of the subtree does not exist.\n");
                break;
            } // if
            if (BST_Balance(tree, rootPtr))
            {
                printf("\nThe subtree is balanced.\n");
            } // if
            else
            {
                printf("\nThe subtree is not balanced.\n");
            } // else
            break;
        } // switch
    } while (true); // do...while

    BST_Destroy(tree);
    free(dataPtr);
    return 0;
} // main