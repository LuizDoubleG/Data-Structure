void StudentListPrint (StudentList* Lst){
    StudentDatas* ptrStudentData;
    ptrStudentData = Lst->firstStudentData->nextStudent;

    printf(" Quantity of students: %d\n", Lst->n - 1);
    while(ptrStudentData != NULL){
        printf("\n Name: %s", ptrStudentData->data->name);
        printf("\n CRE: %0.1lf\n", ptrStudentData->data->CRE);
        ptrStudentData = ptrStudentData->nextStudent;
    }
    free(ptrStudentData);
}
