#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lucky(int n)
{
    if (n%4==0 || n%7==0)
    {
        return true;
    }

    while (n)
    {
   
        if (n%10!=4&&n%10!=7)
        {
            return false;
        }
        n/=10;
        
    }
    return true;
    
}
int main(){
    int n;
    cin>>n;
   
    for (int i = 1; i <= n; i++)
    {
        if (lucky(i)&&n%i==0)
        {
            cout<<"YES";
            return 0;
        }
        
    }
    cout<<"NO";
    
}