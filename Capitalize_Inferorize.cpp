#include <iostream>
using namespace std;
int main(void){
    char a;
    cin>>a;
    if (a>='A' && a<='Z')
    {
        cout<< char((int)a+32);
    }
    else if (a>='a' && a<='z')
    {
        cout<< char((int)a-32);
    }
    
    
}