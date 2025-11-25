#include <stdio.h>
#include <string.h>
void findcharecterpairs(char *str){
    char pairs[50][3];
    int paircount = 0;
    for (int i = 0; str[i] != '\0' && str[i+1] !='\0'; i++)
    {
        pairs[paircount][0]= str[i];
        pairs[paircount][1]= str[i+1];
        pairs[paircount][2]= '\0';
        printf("%s\n", pairs[paircount]);
        paircount++;
    }
    int distinntcount = 0;
    for (int i = 0; i < paircount; i++)
    {
        int isdistinct = 1;
        for (int j = 0; j < paircount; j++)
        {
            if(strcmp(pairs[i], pairs[j])==0)
            {
                isdistinct = 0;
                break;
            }
            
        }
        if (isdistinct)
        {
            distinntcount++;
        }
        
    }
    
    printf("%d\n", distinntcount);
}

    int main(){
        char str[50];
        scanf("%s", str);
        findcharecterpairs(str);
        return 0;
    }
       
