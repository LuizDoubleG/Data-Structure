void StudentDataList_create (char* fileName, StudentList* Lst){
	FILE* ptrStudentDatas;
    char* studentName;
    double* studentCRE;


	ptrStudentDatas = fopen (fileName, "r");
	if(!ptrStudentDatas){
		printf("\n Nao foi possivel abrir a File %s  !\n", fileName);
		exit(1);
	}
    
    do{
       
        studentName = (char*) malloc(50*sizeof(char));
        studentCRE = (double*) malloc(sizeof(double));
        //fscanf(ptrStudentDatas, "%s", studentName);
        //fscanf(ptrStudentDatas, "%s%ld%*c", studentName, studentCRE);
        //fgets(studentName, 50, ptrStudentDatas);
        //fscanf(ptrStudentDatas, "%s %lf", studentName, &studentCRE);
        //fscanf(ptrStudentDatas, "%*s %100[^\n]", studentName);
        fscanf(ptrStudentDatas, "%100[^\n]", studentName);
        fscanf(ptrStudentDatas, "%lf%*c", &studentCRE);
        //fclose(ptrStudentDatas);
        //fscanf(ptrStudentDatas, "%d", studentCRE);
        
    StudentDatas* StudentData = (StudentDatas*) malloc(sizeof(StudentDatas));    
	StudentData->name = studentName;
	StudentData->CRE = studentCRE;
    StudentData->nextStudent = Lst->firstStudentData;
    Lst->firstStudentData = StudentData;
    Lst->n += 1;
    //free(studentName);
    //free(studentCRE);
    //fgetc(ptrStudentDatas);
	}while (!feof(ptrStudentDatas));

    
}


