#include <stdio.h>
#include <string.h>
int main(){
    char first1[200], second1[200];
    char first2[200], second2[200];
    char *space;//pointer
    fgets(first1, sizeof(first1), stdin);
    fgets(first2, sizeof(first2), stdin);

    first1[strcspn(first1,"\n")]='\0';//last newline carecter is replacing by null carecter
    first2[strcspn(first2,"\n")]='\0';

    space = strchr(first1,' ');
    
    if (space!= NULL)
    {
        strcpy(second1, space + 1);//copying the next substring
    }
    else{
        second1[0]='\0';//handling case when no space is found
    }

    space = strchr(first2, ' ');
    if (space != NULL)
    {
        strcpy(second2, space + 1);
    }
    else{
        second2[0]='\0';
    }
    
    if (strcmp(second1,second2) == 0)
    {
        printf("ARE Brothers");
    }else {
        printf("NOT");
    }
}
