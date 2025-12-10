#include<iostream>
using namespace std;
int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    
    int drink = (k*l)/nl;
    int slice = (c*d)/n;
    int salt = p/np;

    int mn = min(min(drink/n,salt/n),slice);

    cout<<mn;
}