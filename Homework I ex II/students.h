#include "struct.h"
//Cria um struct que contera os dados lidos do estudante
//typedef struct studentDatas StudentDatas;
//typedef struct studentList StudentList;

StudentList* createList (void);
//Cria uma lista que contem os dados dos estudantes

void free_Lst(StudentList* Lst);
//Libera a memoria alocada para a lista e seus nós

void StudentDataListCreate (char* fileName, StudentList* Lst);
//Le os dados dos estudantes do ficheiro e os coloca na lista

void StudentListPrint (StudentList* Lst);
//Imprime os dados dos estudantes

#include "list.h"
#include "StudentDataList.h"
#include "StudentListPrint.h"
