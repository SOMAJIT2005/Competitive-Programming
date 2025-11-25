#include <stdio.h>
int triangle(int a, int b, int c){
    if (a*a+b*b == c*c || b*b + c*c == a*a || a*a +c*c == b*b)
    {
        printf("%d %d %d", a, b, c);
    }else{
        printf("not a right angle triangle");
    }
    

}
int main(){
    int x, y, z, w;
    scanf("%d %d %d %d", &x, &y, &z, &w);
    if (x+y>z && x+z>y && y+z>x && x!=0 && y!=0 && z!=0 && w!=0)
    {
        triangle(x, y, z);
    }else{
        triangle(x, y, w);
    }
    
}