#include<bits/stdc++.h>
using namespace std;    
int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int d = v [1] - v[0];
    for (int i = 2; i < v.size(); i++)
    {
        if( v[i] - v[i-1] != d){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}