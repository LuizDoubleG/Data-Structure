#include <stdlib.h>
#include <stdio.h>

int main(void){
	FILE* ptrStudentDatas;
	char* name = (char*)malloc(50*sizeof(char));
	float CRE;
	ptrStudentDatas = fopen ("studentsCRE.txt", "r");
	do{
	fscanf(ptrStudentDatas, "%s", name);
	printf ("%s ", name);	
	}while (fgetc(ptrStudentDatas) != '\n');
}

