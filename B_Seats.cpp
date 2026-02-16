#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s; 
        int count = 0,cnt = 0;

        if(n<=2){
            cout<<1<<endl;
            continue;
        }

        s = '1' + s + '1';

        for (int i = 0; i <= n; i++)
        {
                if (s[i]=='1')
                {
                    if((i-count)/3){
                        if ((i-count)%3==2&&((i-count)/3)>1)
                        {
                            cnt++;
                        }
                        
                        cnt+= (i-count)/3;
                    }
                    cnt++;
                    count = i+1;

                }
                else{
                    cnt++;
                }
                
                
        }
        cout<<cnt-2<<endl;
        
    }
    
}