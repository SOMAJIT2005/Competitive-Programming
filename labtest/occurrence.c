#include <stdio.h>
int main(){
    char str[50];
    int count=0;
    fgets(str, sizeof(str),stdin);
    for (int i = 0; str[i] !='\0' && str[i+2] !='\0'; i++)
    {
        if (str[i]=='a'&& str[i+2]== 'b')
        {
            count++;
        }
        
    }
    printf("number of occurrence = %d", count);
}