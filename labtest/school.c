#include <stdio.h>
#include <string.h>
int main(){
    char sch[20][10], name[20][10];
    int id[20][1]={}, class[20][1]={}, ban[20][1]={}, eng[20][1]={}, math[20][1]={}, sch1=0, sch2=0, avgban=0, hmark=0;
    freopen("in.txt", "r", stdin);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (sch[i]!="school1"||"school2")
            {
                break;
            }
            else
            {
            scanf("%s %d %s %d %d %d %d", sch[i], &id[i][j], name[i], &class[i][j], &ban[i][j], &eng[i][j], &math[i][j]);
            }
        
        }
        
    }
    for (int i = 0; i < 20; i++)
    {
        if (sch[i]=="school1")
        {
            sch1++;
        }
        else
        {
            sch2++;
        }
        
    }
    printf("%d %d", sch1, sch2);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (sch[i]=="school1"&& class[i][j]==7)
            {
                avgban+=ban[i][j];
            }
            
        }
        
    }
    printf("%d", avgban);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (class[i][j]==7 && sch[i]== "school2")
            {
                if (i==0 && j==0)
                {
                    hmark=eng[i][j];
                }
                else{
                    if (eng[i][j]>hmark)
                    {
                        hmark=eng[i][j];
                        
                    }
                    
                }
            }
            
        }
        
    }
}
