typedef struct {
    char* name;
    double* CRE;
}Data;

typedef struct studentDatas{
    Data* data;
    struct studentDatas* nextStudent; 
}StudentDatas;

typedef struct {
	int n;
	StudentDatas* firstStudentData;
}StudentList;

