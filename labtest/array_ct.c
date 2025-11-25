#include <stdio.h>
int main(){
    // set A
    int marks[100][6] = {};
    int k=0;
    double cse_marks=0, cse_count=0, ece_marks=0, ece_count=0;
    freopen("std.txt", "r", stdin);
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
             scanf("%d", &marks[i][j]);
        }
        
    }

    while (k<50)
    {
        if(marks[k][0] == 2)
        {
            cse_marks+= marks[k][2]+ marks[k][3] +marks[k][4] + marks[k][5];
        cse_count++;
        
        }
        else 
        {
            ece_marks+= marks[k][2] + marks[k][3] + marks[k][4] + marks[k][5];
        ece_count++;
        }
        k++;
    }
    int j=0;
    printf("%.2f %.2f", cse_marks/cse_count, ece_marks/ece_count);
    
}