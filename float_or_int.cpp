#include<bits/stdc++.h>
using namespace std;

int main() {
    long double n;
    cin>>n;
    // celi --> smallest integer just "greater" then n ....3.4 -> 4
    //floor --> greatest integer just "smaller" then n ...3.4 -> 3

    if (ceil(n)==floor(n))
    {
        cout<<"int"<<" "<<n;
    }
    else{
        cout<<"float"<<" "<<floor(n)<<" "<<n-floor(n);
    }
    
}

    
    

