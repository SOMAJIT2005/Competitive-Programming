#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        int h=-1,l=x;
        vector<int> a(x);
        for (int i = 0; i < x; i++)
        {
            cin>> a[i];
            if(a[i]==1)
            {
                l = min(l,i);
                h = max(h,i);
            }
        }
        if(h-l+1<=y){
            cout<< "YES" << endl;
        }
        else cout<< "NO" << endl;
        
    }
}