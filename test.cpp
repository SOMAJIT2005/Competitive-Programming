#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int cnt = 0,max = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            if (i!=0&&max>x)
            {
                cnt++;
            }
            else{
            max = x;
            }
        }
        cout<<cnt<<endl;
        
    }
    
}