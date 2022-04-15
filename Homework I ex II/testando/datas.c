#include <stdlib.h>
#include "students.h"

struct studentDatas{
    char* name;
    float* CRE;
    struct studentDatas* nextStudent; 
};

struct studentList{
	int n;
	struct studentDatas* firstStudentData;
};

