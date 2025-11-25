#include <stdio.h>
#include <string.h>
int isconcatination(char arr[100][50], int size, int index){
    char temp[100];
    int i, j;
    for (int i = 0; i < size; i++)
    {
        for ( j = 0; j < size; j++)
        {
            if (i != j)
            {
                strcpy(temp," "); // initialize temp to an empty string . otherwise strcat will not work
                strcat(temp,arr[i]);
                strcat(temp, arr[j]);
                if (strcmp(temp, arr[index])==0)
                {
                    return 1;
                }
            }
            
        }
        
    }
    return 0;
    
}
int main(){
    int n, i , count =0;
    char arr[100][50];
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (isconcatination(arr, n, i))
        {
            count++;
        }
        
    }
    return 0;

}