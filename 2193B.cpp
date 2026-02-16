#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &x:a) cin>>x;  

        int l = 0,h= 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i]!=n-i)
            {
                l = i;
                break;
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i]==n-i)
            {
                h = i;
                break;
            }
            
        }
        if (l<=n-1&&h<=n-1)
        {
            reverse(a.begin()+l,a.begin()+h+1);

        }
        
        
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }

        cout<<endl;
        
        
    }
    
}