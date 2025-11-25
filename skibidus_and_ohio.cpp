#include<iostream>
using namespace std;
int solve(){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]==s[i+1])
        {
            return 1;
        }
        
    }
    return s.length();
    
}

int main(){
    int n;
    cin>> n;
    while(n--){
        cout<< solve()<< endl;
        
    }
}