#include <stdio.h>
#include <string.h>
void funcstr(char *word){
    int l = strlen(word);
    if (l>10)
    {
        printf("%c%d%c\n",word[0], l-2, word[l-1]);
    }
    else{
        printf("%s\n", word);
    }
    
}
int main(){
    char str[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",str);
        funcstr(str);
    }
    
}