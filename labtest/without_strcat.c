#include <stdio.h>
#include <string.h>
void mycat(char *str1, char *str2);
int main(){
    char str1[100], str2[100];
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    mycat(str1, str2);
    printf("%s",str1);
    return 0;
}
void mycat(char *str1, char *str2){
int i = 0, j = 0, k = 0, l = 0;
i = strlen(str1);
j = strlen(str2);
k = i + j ;
for (int z = i; z < k; z++)
{
    str1[z]= str2[l];
    l++;
}
str1[k] = '\0';    
}
/*void mycat(char *str1, char *str2)
{
    while (*str1)
    {
        str1++;
    }
    while (*str2)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
}

int main()
{
    char str1[100];
    char str2[100];
    scanf("%s", str1);
    scanf("%s", str2);

    mycat(str1, str2);
    printf("%s", str1);

    return 0;
}*/