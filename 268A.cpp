#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int>home(n),guest(n);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int h,g;
        cin>>h>>g;
        home[i]=h;
        guest[i]=g;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (home[i]==guest[j])
            {
                count++;
            }
            
        }
        
    }
    

    cout<<count;
    
    
}