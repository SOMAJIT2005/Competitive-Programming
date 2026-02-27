#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];

    int cnt1=0,cnt0=0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        if (x%2==0)
        {
            cnt1++;
        }
        else
        {
            cnt0++;
        }
        
    }

    if (cnt1>cnt0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i]%2!=0)
            {
                cout<<i+1<<endl;
                break;
            }
            
        }
        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i]%2==0)
            {
                cout<<i+1<<endl;
                break;
            }
            
        }
        
    }
    
}