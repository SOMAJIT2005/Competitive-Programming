#include <stdio.h>
int main(){
    int a, b[1000][3]={}, count1 = 0;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
        
    }
    for (int i = 0; i < a; i++)
    {
        int count = 0;// reset count for every row;
        for (int  j = 0; j < 3; j++)
        {
            if (b[i][j] == 1)
            {
                count++;
            }
            
        }
        if (count > 1)
        {
            count1++;
        }
        
    }
    printf("%d",count1);
    

    
}