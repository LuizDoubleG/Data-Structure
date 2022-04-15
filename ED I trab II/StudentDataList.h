void StudentDataListCreate (char* fileName, StudentList* Lst){
	FILE* ptrStudentDatas;
    char* studentName;
    double* studentCRE;


	ptrStudentDatas = fopen (fileName, "r");
	if(!ptrStudentDatas){
		printf("\n Nao foi possivel abrir a File %s  !\n", fileName);
		exit(1);
	}
    
    do{
        StudentDatas* StudentData = (StudentDatas*) malloc(sizeof(StudentDatas)); 
        Data* data = (Data*) malloc(sizeof(Data)); 

        studentName = (char*) malloc(50*sizeof(char));
        studentCRE = (double*) malloc(sizeof(double));

        fscanf(ptrStudentDatas, "%100[^\n]", studentName);
        fscanf(ptrStudentDatas, "%lf%*c", &studentCRE);
        data->name = studentName;
        data->CRE = studentCRE;
        StudentData->data = data;
        StudentData->nextStudent = Lst->firstStudentData;
        Lst->firstStudentData = StudentData;
        Lst->n += 1;
         
	}while (!feof(ptrStudentDatas));

    fclose(ptrStudentDatas);
    free(studentName);
    free(studentCRE);
}


