#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> p(n),a(n);
        for(auto &i:p){
            cin>>i;
        }
        for(auto &i:a){
            cin>>i;
        }
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            if (a[i]!=p[i])
            {
                if (((i>0)&&(a[i]==p[i-1]))||((i<=n-1)||(a[i]==p[i+1])))
                {
                    flag = true;
                    break;
                }
                
            }
        }

        if (flag)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    
}