#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int required_time = 0;

    for (int i = 1; i <= n; i++)
    {
        required_time += i*5;         
        if (required_time+k>240)
        {
            cout<<i-1;
            return 0;
        }
        
    }
    cout<<n;
    
}