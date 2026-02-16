#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,x,y;
        cin>>n>>x>>y;

        long long sum = 0,amount=0,cnt=0;

        for (int i = 0; i < n; i++)
        {
            cin>>amount;
            if (amount%x==0)
            {
                sum+=amount/x;
            }
            else{
                sum+=amount/x;
                cnt+=amount%x;
            }
            
        }

        cout<<sum*y+(cnt/x)*y+1<<endl;
        
    }
}
    