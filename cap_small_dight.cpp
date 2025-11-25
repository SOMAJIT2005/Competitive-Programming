#include <iostream>
using namespace std;
int main(void){
    char a;
    cin>>a;
    if (a >= 'A' && a <= 'Z'){
        cout<< "ALPHA"<< endl<< "IS CAPITAL";
    }
    else if (a >= 'a' && a <= 'z'){
        cout<< "ALPHA"<< endl<< "IS SMALL";
    }
    else if (a >= '0' && a <= '9'){
        cout<< "IS DIGIT";
    }
}