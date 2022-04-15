StudentList* createList (void){
	StudentList* List;
	List = (StudentList*) malloc(sizeof(StudentList));
	if (List){
   		List -> n = 0;
   		List -> firstStudentData = NULL;
	}
	return List;
}
