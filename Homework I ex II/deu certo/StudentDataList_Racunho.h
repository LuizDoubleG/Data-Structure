//read file
//1st line: Name
//2nd line: CRE
//Space line: Next node
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include "datas.c"

// void geraLista(StudentList* Lst) {
// 	FILE* ptrStudentDatas;
// 	char c;
// 	Lst -> n = 0;
// 	Lst -> firstStudentData = NULL;
// 	while(!feof(ptrStudentDatas)){ 
// 		c = fgetc(ptrStudentDatas);
		
// 		if (c==-1 || c==10){ //eliminar quebra de linha /n e caractere /0
// 			continue;
// 		}
// 		/*if (verificaRep(c,Lst)>=1){ //caso haja repetição (count==1) nao isere na lista novamente
// 			continue;
// 		}
// 		*/
// 		StudentData_insert(c,Lst);//pode usar com else tambem	
		
//CTRL + K + C


void StudentDataList_create (char* fileName, StudentList* Lst){
	FILE* ptrStudentDatas;
	//int count = 0;
	//char name[STRING_SIZE] = {0};
    char* studentName;
    float* studentCRE;
    StudentDatas* StudentData = (StudentDatas*) malloc(sizeof(StudentDatas));
    //float* CRE;
  //Lst = (StudentList*) malloc(sizeof(StudentList));
   //Lst -> n = 0;
   //Lst -> firstStudentData = NULL;

	ptrStudentDatas = fopen (fileName, "r");
	if(!ptrStudentDatas){
		printf("\n Nao foi possivel abrir a File %s  !\n", fileName);
		exit(1);
	}

	//Pass name of student to first node
	/*while(fgetc(ptrStudentDatas) != EOF){ 
		fgetc(ptrStudentDatas);
        ////name[count] = fgetc(ptrStudentDatas);
		count++;
	}
    */
    //while ((fscanf(ptrStudentDatas, "%s", studentName) || (fscanf(ptrStudentDatas, "%f", studentCRE)))!= EOF){
    //while ((token = fgetc(ptrStudentDatas)) != EOF){
        //fgets(name, STRING_SIZE, fp); 
        //studentName = (char*) malloc(sizeof(strlen(name)));
        studentName = (char*) malloc(50*sizeof(char));
        studentCRE = (float*) malloc(sizeof(float));
        //*studentCRE = 1.0;
        fscanf(ptrStudentDatas, "%s", studentName);
        fscanf(ptrStudentDatas, "%f", studentCRE);
        ////strcpy(*studentName, name);
    ////fscanf(ptrStudentDatas, "%s", name);
    //fgetc(ptrStudentDatas);

    ////memset(name, STRING_SIZE, 0);
    //count = 0;
    
	StudentData->name = studentName;
	StudentData->CRE = studentCRE;
    StudentData->nextStudent = Lst->firstStudentData;
    Lst->firstStudentData = StudentData;
    Lst->n += 1;
	//}
	//count = 0;
	/*while(fgetc(ptrStudentDatas) != '\n'){
		fgetc(ptrStudentDatas);
		CRE[count] = fgetc(ptrStudentDatas);
		count++;
	}
    */
}


