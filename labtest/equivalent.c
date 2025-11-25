#include <stdio.h>
int main(){
    int A, B, m =0,n=0, i =0, arr[100]={}, arr2[100]={},j=0, count =0, count1 =0;
    scanf("%d %d", &A, &B);
        while (A!=0)
    {
        m=A%10;
        A=A/10;
        arr[i]=m;
        i++;
    }
        while (B!=0)
    {
        n=B%10;
        B=B/10;
        arr2[j]=n;
        j++;
    }
    for (int k= 0; k < 10 ; k++)
    {
        for (int l = 0; l < 10; l++)
        {
            if (arr[k]== arr2[l])
            {
                count++;
            }else{ break;}
            
        }
        
        
    }
        for (int k= 0; k < 10 ; k++)
    {
        for (int l = 0; l < 10; l++)
        {
            if (arr2[k]== arr[l])
            {
                count1++;
            }else{ break;}
            
        }
        
        
    }
    if (count1 + count == i+j)
    {
        printf("equivalent");
    }
}