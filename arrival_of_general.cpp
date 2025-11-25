#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    int n;
    int mx = INT8_MIN, mn = INT8_MAX;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        mx = max(mx,arr[i]);
        mn = min(mn,arr[i]);
    }
    if (mx == arr[0]&& mn == arr[n-1])
    {
        cout<<0;
    }
    else{
    auto mxit = find(arr.begin(),arr.end(),mx);
    auto mnit = find(arr.rbegin(),arr.rend(),mn);


    int maxindex = mxit - arr.begin();
    int minindex = mnit.base() - arr.begin()-1;
    int steps = maxindex + (n - 1 - minindex);
    if (maxindex>minindex)//point to be highlighted. overlapling.
    {
        steps--;
    }
    cout<<steps;
    
    }
    
}