#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    for(i = 0; i <= j; i++){ // Indexes walk until they meet, they don't have to go all the way
        if(str[i] != str[j]){
            *flag = 1;
            break;
        }
        j--;
    }    
}

int main (void){
    FILE* fp;
    char str[100], original[100];
    int flag = 0;

    fp = fopen("palindrome.txt", "r");
    if (fp == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    while (!feof(fp)){
        flag = 0;

        fscanf(fp, "%100[^\n]%*c", str);
        strcpy(original, str);

        lowercase(str);
        remove_spaces(str);

        verify_palindrome(str, &flag);
        
        if(flag == 1){
            printf("The string: '%s' is not a palindrome.\n", original);
        }
        else{
            printf("The string: '%s' is a palindrome.\n", original);
        }
    }
}
