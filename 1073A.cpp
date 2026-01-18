#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        bool flag=true;
        
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for (int i = 0; i+1 < n; i++)
        {
            if (arr[i]%2==arr[i+1]%2)
            {
                flag=false;
                break;
            }
            
        }
        
        if (flag)
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        
        

    }
    


    
}