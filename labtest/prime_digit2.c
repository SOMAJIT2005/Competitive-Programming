#include <stdio.h>
int main(){
    int A,m,arr[10]={},i=0, sum=0;
    scanf("%d", &A);
    while (A!=0)
    {
        m=A%10;
        A=A/10;
        arr[i]=m;
        i++;
    }
    for (int j = 0; j <= i-1; j++)
    {
        if (arr[j]==2||arr[j]==3||arr[j]==5||arr[j]==7 )
        {
            sum+=arr[j];
        }
        
    }
    printf("%d",sum);   
}