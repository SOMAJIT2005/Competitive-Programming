#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        long long a[n];
        long long diff=0,temp=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(abs(temp-a[i])>1&&temp>a[i]&&i!=0)
            {
                diff=max(abs(a[i]-temp),diff);
            }
            temp=a[i];
        }

        if(diff>1){
            cout<<diff<<endl;
        }
        else{
            cout<<-1<<endl;
        }

    }
}
    