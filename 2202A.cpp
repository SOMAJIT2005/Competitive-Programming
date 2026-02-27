#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long a,b;
        cin>>a>>b;

        int cnt=0,rem=0,div=0;


        if (a>=2)
        {
            rem = a%2;
            div = a/2;
            cnt+=div;

            rem = rem%3;
            div = rem/3;

            rem = rem%4;
            div = rem/4;
            cnt -= div;

        }

        if(b==cnt){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
        
    }
    
}