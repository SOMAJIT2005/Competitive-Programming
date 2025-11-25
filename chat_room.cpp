#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s,a = "hello";
    cin>>s;

    int l = s.length(),j = 0;

    auto it = find(s.begin(),s.end(),'h');
    
    for (int i = it - s.begin(); i < l; i++)
    {
        if (s[i]==a[j])
        {
            j++;
        }
        
    }

    if (j == a.length())
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    
}