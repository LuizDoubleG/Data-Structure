#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <locale.h> 


// void remove_spaces(char* str) {
//     int i, j;
//     for (i = 0, j = 0; str[i] != '\0'; i++) {
//         if (str[i] != ' ') {
//             str[j++] = str[i];
//         }
//     }
// }
void lowercase(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

void remove_spaces(char* str) {
int i, j;
char* d = str;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*str++ = *d++);
}

void verify_palindrome(char* str, int* flag){
    int i, j, len;
    len = strlen(str);
    j = len - 1;
    for(i = 0; i < len; i++){
        if(str[i] != str[j]){
            *flag = 1;
            break;
        }
        j--;
    }    
}

int main (void){
    //setlocale (LC_ALL, "Portuguese");
    FILE* fp;
    char str[100], original[100];
    //char* str;
    int flag = 0, len;

    fp = fopen("palindrome.txt", "r");
    if (fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    while (!feof(fp)){
    	//str = (char*) malloc(100 * sizeof(char));
        flag = 0;
        //fgets(str, 100, fp);
        fscanf(fp, "%100[^\n]%*c", str);
        strcpy(original, str);

        lowercase(str);
        remove_spaces(str);
      
        //   strcat(str,aux);

        verify_palindrome(str, &flag);
        
        if(flag == 1){
            printf("The string: '%s' is not a palindrome.\n", original);
        }
        else{
            printf("The string: '%s' is a palindrome.\n", original);
        }
    }
}
