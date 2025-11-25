#include <bits/stdc++.h>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>> s;
        int n = s.length();
        int run = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i]!= s[i-1])