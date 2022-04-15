//read file
//1st line: Name
//2nd line: CRE
//Space line: Next node
void geraLista(StudentList* Lst) {
	FILE* ptrStudentDatas;
	char c;
	Lst -> n = 0;
	Lst -> firstStudentData = NULL;
	while(!feof(arq)){ 
		c = fgetc(ptrStudentDatas);
		
		if (c==-1 || c==10){ //eliminar quebra de linha /n e caractere /0
			continue;
		}
		/*if (verificaRep(c,Lst)>=1){ //caso haja repetição (count==1) nao isere na lista novamente
			continue;
		}
		*/
		StudentData_insert(c,Lst);//pode usar com else tambem	
		
	}
	fclose(arq);
}
StudentData* StudentData_insert (char* fileName){
	File* ptrStudentDatas;
	int count = 0;
	char* studentName;
	char name[50];
	ptrStudentDatas = fopen (fileName, "r");
	if(!ptrStudentDatas){
		printf("\n Nao foi possivel abrir a File %s  !\n", fileName);
		exit(1);
	}

	//Pass name of student to first node
	while(fgetc(ptrStudentDatas) != '\n'){ 
		fgetc(ptrStudentDatas);
		count++;
	}
	studentName = (char*) malloc(count*sizeof(char));
	fseek(ptrStudentDatas, 0, SEEK_SET);
	while(fgetc(ptrStudentDatas) != '\n'){ 
		fgetc(ptrStudentDatas);
		count++;
	}
	StudentData->name = studentName;
	count = 0;
	while(fgetc(ptrStudentDatas) != '\n'){
		fgetc(ptrStudentDatas);
		if (fgetc(ptrStudentDatas) == '\n'){
	   	 	studentName = (char*) malloc(count*sizeof(char));
			StudentData->name = studentName;
		}
		count++;
	}

}
