#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,j,k;
        cin>>n>>j>>k;
        vector<int>arr(n);
        for(auto &i : arr)
        {
            cin>>i;
        }

        if (k==1 && arr[j-1]!=*max_element(arr.begin(),arr.end()))
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        

    }
    
   
   
    

}