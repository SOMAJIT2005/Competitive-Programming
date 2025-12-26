#include<iostream>
using namespace std;
int main(){
    long long a;
    cin>>a;
    int count = 0;
    while (a)
    {
        if (a%2!=0)
        {
            count++;
            a = a-1;
            a = a/2;
            continue;
        }
        else{
            a = a/2;
        }
        
        
    }
    cout<<count;
    
    
}