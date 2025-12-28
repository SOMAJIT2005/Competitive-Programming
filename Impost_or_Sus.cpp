#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int l = s.length();

        int cnt1 = 0;
        if (s[0]!='s')
        {
            s[0]='s';
            cnt1++;
        }
        if (s[l-1]!='s')
        {
            s[l-1]='s';
            cnt1++;
        }
        
        int cnt2 = 0;
        for (int i = 0; i < l; i++)
        {
            if (s[i]=='u')
            {
                cnt2++;
            }
            else{
                cnt1+=cnt2/2;
                cnt2 = 0;
            }
            
        }

        cout<<cnt1<<endl;
        
        
    }
    
}