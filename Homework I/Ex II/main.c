#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

int main() {
	StudentList* Lst;
	Lst = createList();
	StudentDataListCreate ("studentsCRE.txt",Lst);
	StudentListPrint(Lst);
	free_Lst(Lst); 
}
 
