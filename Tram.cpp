#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int passengers = 0;
    int capacity = 0;
    while (n--)
    {
        int a,b;
        cin>>a>>b;

        passengers-=a;
        passengers+=b;

        capacity = max(capacity,passengers);

    }
    cout<<capacity;
    
    
    
}