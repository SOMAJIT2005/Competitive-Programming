#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long p,q;
        cin>>p>>q;

        if(p>=q){
            cout<<"Alice"<<endl;
        }
        else if (p*3<q*2)//(p/q)<(2/3)
        {
            cout<<"Alice"<<endl;
        }
        
        else{
            cout<<"Bob"<<endl;
        }
        
    }
}