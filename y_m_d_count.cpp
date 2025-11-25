#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>> t;
    cout<< t/365 << " years"<<  endl << (t%365)/30 << " months"<< endl << t -t/365*365 - (t%365)/30*30 << " days"<< endl; 

}
  