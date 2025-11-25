#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long a,b;
        cin>>a>>b;
        if (a%b==0)
        {
            cout<<0<<endl;
        }
        else if(a<b)
        {
            cout<<b-a<<endl;
        }
        else{
            long long x = ceil((double)a/b);
            cout<<b*x-a<<endl;
        }
        
        
    }
    
}