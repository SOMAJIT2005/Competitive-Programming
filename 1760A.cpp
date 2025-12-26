#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        int sum = a+b+c;

        cout<<sum - (max(max(a,b),c)+min(min(a,b),c))<<endl;
        
    }
    
}