#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,d;
        cin>>n>>m>>d;

        int max_bx = (d/m)+1;

        int tower = ceil((float)n/max_bx);

        cout<<tower<<endl;

        
        
    }
    
}