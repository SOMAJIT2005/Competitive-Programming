#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        vector<int>arr(a);
        int count = 0,ans = 0 ;
        for (int i = 0; i < a; i++)
        {
            cin>>arr[i];
            if (arr[i]==0)
            {
                count++;
                if (count == b)
                {
                    count = -1;// to skip the next o for hike break..
                    // but samely count = 0 and i++ statement will not work.
                    ans++;
                }
                
            }
            else{
                count = 0;
            }
               
        }
        cout<<ans<<endl;
        
    }
    
}