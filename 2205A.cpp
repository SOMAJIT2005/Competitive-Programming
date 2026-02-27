#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n ;
        cin>>n;
        int a[n];

        int mx = 0;        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(a[i]==n)
            {
                mx = i;;
            }
        }    

        swap(a[0],a[mx]);

        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
}