#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeADT.h"

#define MAX_NAME_LENGTH 28

// Student Node Structure Definition
typedef struct
{
    char name[MAX_NAME_LENGTH];
    int cellNumber;
} Student; 

int compareChar (void* student1, void* student2);

void printBST(void* num1);

int menu(void);

void choice(BST_TREE* mainTree, int option);


int main()
{
// Local Definitions
    BST_TREE* BSTRoot;

// Statements
    BSTRoot = BST_Create(compareChar);
    while (true)
    {
        choice(BSTRoot, menu());
    }
    return 0;
} // main

int compareChar (void* student1, void* student2)
{
// Local Definitions
    char key1[MAX_NAME_LENGTH], key2[MAX_NAME_LENGTH]; 
    int i;

// Statements
    strcpy(key1, ((char*)((Student*)student1)->name));
    strcpy(key2, ((char*)((Student*)student2)->name));
    for(i = 0; i < strlen(key2); i++)
    {
        if(key1[i] < key2[i])
        {
            return -1;
        } // if
        else if(key1[i] > key2[i])
        {
            return 1;
        } // else if
    } // for
    return 0;
} // compareChar

void printBST(void* student)
{
    printf(" %s   -   %d   \n", ((Student*)student)->name, ((Student*)student)->cellNumber);
    return;
} // printBST

int menu()
{
// Local Definitions
    int option = 0;

// Statements
    system("pause");
    system("cls");
    printf("\nRealize a operacao desejada:\n");
    printf("1. Imprimir\n");
    printf("2. Inserir novo aluno\n");
    printf("3. Remover aluno \n");
    printf("4. Buscar um aluno\n");
    printf("5. Sair\n");
    printf("\nSua escolha: ");
    scanf("%d", &option);
    return option;
} // menu

void choice(BST_TREE* mainTree, int option)
{
// Local Definitions
    char name[MAX_NAME_LENGTH];
    Student* student;

// Statements
    student = (Student*)malloc(sizeof(Student));
    switch (option)
    {
    case 1:
        if(!BST_Empty(mainTree))
        {
            printf("\nLista:\n|Alunos| |Celular|\n");
            BST_Traverse(mainTree, printBST);
        } // if
        else
        {
            printf("\nA arvore esta vazia!\n");
        } // else
        break;

    case 2:
        printf("\nDigite o nome do aluno: ");
        scanf("%s[^\n]", student->name);
        printf("\nDigite o numero de telefone do aluno: ");
        scanf("%d", &(student->cellNumber));
        if (BST_Insert(mainTree, student))
        {
            printf("\nAluno inserido com sucesso!\n");
        } // if
        else
        {
            printf("\nErro inesperado ao inserir aluno!\n");
        } // else
        break;

    case 3:
        printf("\nDigite o nome do aluno que sera excluido: ");
        scanf("%s[^\n]", &name);
        if (BST_Delete(mainTree, name))
        {
            printf("\nAluno %s excluido da lista com sucesso!\n", name);
        } // if
        else
        {
            printf("\nAluno nao encontrado!\n");
        } // else
        break;

    case 4:
        printf("\nDigite o nome do aluno que sera buscado: ");
        scanf("%s[^\n]", &name);
        if (!BST_Empty(mainTree))
        {
            if (BST_Retrieve(mainTree, name))
            {
                printf("\nAluno %s esta na lista!\n", name);
            } // if
            else
            {
                printf("\nAluno nao encontrado!\n");
            } // else
        } // if
        else
        {
            printf("\nA lista esta vazia!\n");
        } // else
        break;
    case 5:
        printf("\nEncerrando programa...\n\n");
        exit(1);
        break;

    default:
        printf("\nOpcao invalida\n");
    }
} // choice



