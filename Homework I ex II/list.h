StudentList* createList (void){
	StudentList* List;
	List = (StudentList*) malloc(sizeof(StudentList));
	if (List){
   		List -> n = 0;
   		List -> firstStudentData = NULL;
	}
	return List;
}

void free_Lst(StudentList* Lst){
	StudentDatas* ptrStudentData;
	while(Lst->firstStudentData != NULL){
		ptrStudentData = Lst->firstStudentData;
		Lst->firstStudentData = Lst->firstStudentData->nextStudent;
		free(ptrStudentData);
	}
	free(Lst);
}