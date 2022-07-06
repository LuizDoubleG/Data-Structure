#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 25

typedef struct
{
    char letter;
    int frequency;
}LetterfreqNode;

typedef struct
{
    LetterfreqNode* dataPtr;
    struct Node* left;
    struct Node* right;
}NODE;

NODE* createTree()
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    LetterfreqNode* data = (LetterfreqNode*)malloc(sizeof(LetterfreqNode));
    data -> letter = ' ';
    data -> frequency = 0;
    newNode -> dataPtr = data;
    newNode -> right = NULL;
    newNode -> left = NULL;
}

void* tree_Insert(NODE* tree, NODE* Node)
{
    tree->dataPtr->frequency += Node->dataPtr->frequency;
    if (!tree->left)
        tree->right = Node;
    else
        tree->left = Node;
}

NODE* Node_Create(LetterfreqNode *data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->dataPtr = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main(){
    LetterfreqNode *node;
    int i,j;
    FILE* fPtr;
    char fileID[MAX_FILE_NAME];
    LetterfreqNode* node = (LetterfreqNode*)malloc(26*sizeof(LetterfreqNode));

    // Ask user for file name
    printf ("Enter the file name for file to have its words classified: ");
    scanf("%s", fileID);

    // Open file
    fPtr = fopen(fileID, "r");
    if (fPtr == NULL){
        printf("File '%s' could not be opened.\n", fileID);
        return 100;
    } // if

    node = (LetterfreqNode*)malloc(sizeof(LetterfreqNode));
    
    for (j=0; j<26; j++)
    {
        node->letter = 'a' + j;
        node->frequency = 0;
        tree_Insert(node, Node_Create(node));
    }

    for (j=0; j<26; j++)
    {   
        tree = treeCreate();
        for (i = 0; i < 2; i++)
        {
            tree_Insert(tree, Node);
        }
    }
    
} // main