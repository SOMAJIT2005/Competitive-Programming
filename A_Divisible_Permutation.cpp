#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        int j=1;
        for(int i=n-1; i>=0;i-=2){
            v[i]=j;
            j++;
        }
        j=n;
        for (int i = n-2; i >=0;i-=2)
        {
            v[i]=j;
            j--;
        }

        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
    
}
